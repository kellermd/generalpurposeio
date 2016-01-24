#include "DHT.h"
#include "Scheduler.h"

#include <iostream>

// This is the only processor specific magic value, the maximum amount of time to
// spin in a loop before bailing out and considering the read a timeout.  This should
// be a high value, but if you're running on a much faster platform than a Raspberry
// Pi or Beaglebone Black then it might need to be increased.
#define DHT_MAXCOUNT 32000

// Number of bit pulses to expect from the DHT.  Note that this is 41 because
// the first pulse is a constant 50 microsecond pulse, with 40 pulses to represent
// the data afterwards.
#define DHT_PULSES 41

namespace Common
{
  DHT::DHT()
  {

  }

  DHT::DHT(GPIO & gpio)
  {
  }
  
  DHT::DHT(const DHT& other)
  {

  }

  DHT::~DHT()
  {

  }

  DHT& DHT::operator=(const DHT& other)
  {

  }

  bool DHT::operator==(const DHT& other) const
  {

  }
  
  // --------------------------------------------------------------------------

  int DHT::dht_read(Common::GPIO & gpio, int type, int gpio_base, int gpio_number, float* humidity, float* temperature)
  {

    // Validate humidity and temperature arguments and set them to zero.
    if (humidity == NULL || temperature == NULL) {
      return DHT_ERROR_ARGUMENT;
    }
    
    *temperature = 0.0f;
    *humidity = 0.0f;

    // Initialize GPIO library.d
    gpio.Init();
    
    Common::PulseCounts * pulseCountsObject = new Common::PulseCounts(DHT_PULSES * 2); 
    int * & pulseCountsArray = pulseCountsObject->rArray();

    // Set pin to output.
    // pi_2_mmio_set_output(pin);
    gpio.SetOutput(); 

    // Bump up process priority and change scheduler to try to try to make process more 'real time'.
    // set_max_priority();
    Common::Scheduler scheduler;  
    scheduler.set_max_priority(); // Common::Scheduler destructor will set back to normal priority

    // Set pin high for ~500 milliseconds.
    //pi_2_mmio_set_high(pin);
    //sleep_milliseconds(500);
    gpio.SetHigh(500);


    // The next calls are timing critical and care should be taken
    // to ensure no unnecssary work is done below.

    // Set pin low for ~20 milliseconds.
    //pi_2_mmio_set_low(pin);
    //busy_wait_milliseconds(20);
    gpio.SetLow(20);
    
    // Set pin at input.
    // pi_2_mmio_set_input(pin);
    gpio.SetInput();

    // Need a very short delay before reading pins or else value is sometimes still low.
    for (volatile int i = 0; i < 50; ++i) {
    }

    gpio.ReadPulseCounts(*pulseCountsObject, (int)DHT_MAXCOUNT);

    // Done with timing critical code, now interpret the results.

    // Drop back to normal priority.
    //set_default_priority();
    scheduler.set_default_priority();

    // Compute the average low pulse width to use as a 50 microsecond reference threshold.
    // Ignore the first two readings because they are a constant 80 microsecond pulse.
    uint32_t threshold = 0;
    for (int i=2; i < DHT_PULSES*2; i+=2) {
      threshold += pulseCountsArray[i];
    }
    threshold /= DHT_PULSES-1;

    // Interpret each high pulse as a 0 or 1 by comparing it to the 50us reference.
    // If the count is less than 50us it must be a ~28us 0 pulse, and if it's higher
    // then it must be a ~70us 1 pulse.
    uint8_t data[5] = {0};
    for (int i=3; i < DHT_PULSES*2; i+=2) {
      int index = (i-3)/16;
      data[index] <<= 1;
      if (pulseCountsArray[i] >= threshold) {
	// One bit for long pulse.
	data[index] |= 1;
      }
      // Else zero bit for short pulse.
    }

    // Useful debug info:
    std::cout << "Data:" << (int)data[0] << " " <<  (int)data[1] << " " <<  (int)data[2] << " " <<  (int)data[3] << " " <<  (int)data[4] << "\n"; // 0x%x 0x%x 0x%x 0x%x 0x%x

    // Verify checksum of received data.
    if (data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF)) {
      if (type == DHT11) {
	// Get humidity and temp for DHT11 sensor.
	*humidity = (float)data[0];
	*temperature = (float)data[2];
      }
      else if (type == DHT22) {
	// Calculate humidity and temp for DHT22 sensor.
	*humidity = (data[0] * 256 + data[1]) / 10.0f;
	*temperature = ((data[2] & 0x7F) * 256 + data[3]) / 10.0f;
	if (data[2] & 0x80) {
	  *temperature *= -1.0f;
	}
      }
      std::cout << "Humidity:" << *humidity << "; " <<  "Temperature:" << " " <<  *temperature;
      return DHT_SUCCESS;
    }
    else {
      return DHT_ERROR_CHECKSUM;
    }    
    return DHT_SUCCESS;
  }

} // end namespace Common