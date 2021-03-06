#include "GPIO.h"
#include "../Common/GPIO.h"
//#include "pi_2_mmio.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdexcept>

namespace RaspberryPi2 
{
  GPIO::GPIO()
  {
    GPIO::Init();
  }

  GPIO::GPIO(const GPIO& other)
  {

  }

  GPIO::~GPIO()
  {

  }

  GPIO& GPIO::operator=(const GPIO& other)
  {

  }

  bool GPIO::operator==(const GPIO& other) const
  {

  }

  GPIO::GPIO(const Common::GPIO& other)
  {

  }

  GPIO::GPIO(std::string pin) : Common::GPIO(pin)
  {
    this->Init();
    this->SetGPIONumber(pin);
  }
  
  const std::string GPIO::GPIO1 = "GPIO1";
  const std::string GPIO::GPIO2 = "GPIO2";
  const std::string GPIO::GPIO3 = "GPIO3";
  const std::string GPIO::GPIO4 = "GPIO4";
  const std::string GPIO::GPI23 = "GPI23";
  const std::string GPIO::GPI24 = "GPI24";
  
  int GPIO::Init()
  {
    if (pi_2_mmio_init() != MMIO_SUCCESS)
    {
      throw std::logic_error("Unable to initialize GPIO memory map");
    }
  }
  
  void GPIO::SetGPIONumber(std::string pin)
  {
    if      (pin == GPIO::GPIO1) {_gpio_number = 1;}
    else if (pin == GPIO::GPIO2) {_gpio_number = 2;}
    else if (pin == GPIO::GPIO3) {_gpio_number = 3;}
    else if (pin == GPIO::GPIO4) {_gpio_number = 4;}
    else if (pin == GPIO::GPI23) {_gpio_number = 23;}
    else if (pin == GPIO::GPI24) {_gpio_number = 24;}
    else {throw std::logic_error("GPIO pin not implemented");}
  }
  
  void GPIO::SetOutput()
  {
    pi_2_mmio_set_output(this->_gpio_number);
  }
  
  void GPIO::SetInput()
  {
    pi_2_mmio_set_input(this->_gpio_number);
  }
  
  void GPIO::SetHigh(int millis)
  {
    pi_2_mmio_set_high(this->_gpio_number);
    this->sleep_milliseconds(millis);
  }
  
  void GPIO::SetLow (int millis)
  {
    pi_2_mmio_set_low(this->_gpio_number);
    this->busy_wait_milliseconds(millis);
  }

  int GPIO::GetValue()
  {
    return pi_2_mmio_input(_gpio_number);
  }

  
  void GPIO::ReadPulseCounts(Common::PulseCounts & pulseCountsObject, int maxCount)
  {
    int * pulseCounts = pulseCountsObject.rArray();
    int pulseCountsArraySize = pulseCountsObject.Count();
    int _gpio_number = this->_gpio_number;
    
    // Wait for DHT to pull pin low.
    uint32_t count = 0;
    while (pi_2_mmio_input(_gpio_number)) {
      if (++count >= maxCount) {
	// Timeout waiting for response.
	//set_default_priority();
	throw std::runtime_error("Timeout waiting for pin to be pulled low"); // return; // DHT_ERROR_TIMEOUT;
      }
    }

    // Record pulse widths for the expected result bits.
    for (int i=0; i < pulseCountsArraySize; i+=2) {
      // Count how long pin is low and store in pulseCounts[i]
      while (!pi_2_mmio_input(_gpio_number)) {
	if (++pulseCounts[i] >= maxCount) {
	  // Timeout waiting for response.
	  //set_default_priority();
	  throw std::runtime_error("Timeout waiting for pin to be pulled high");// return; //  DHT_ERROR_TIMEOUT;
	}
      }
      // Count how long pin is high and store in pulseCounts[i+1]
      while (pi_2_mmio_input(_gpio_number)) {
	if (++pulseCounts[i+1] >= maxCount) {
	  // Timeout waiting for response.
	  //set_default_priority();
	  throw std::runtime_error("Timeout waiting for pin to be pulled low"); // return; //  DHT_ERROR_TIMEOUT;
	}
      }
    }
  }
  
  volatile uint32_t* GPIO::pi_2_mmio_gpio = NULL;
  #define GPIO_BASE_OFFSET 0x200000
  #define GPIO_LENGTH 4096
  
  int GPIO::pi_2_mmio_init() {
    if (pi_2_mmio_gpio == NULL) {
      // Check for GPIO and peripheral addresses from device tree.
      // Adapted from code in the RPi.GPIO library at:
      //   http://sourceforge.net/p/raspberry-gpio-python/
      FILE *fp = fopen("/proc/device-tree/soc/ranges", "rb");
      if (fp == NULL) {
	return MMIO_ERROR_OFFSET;
      }
      fseek(fp, 4, SEEK_SET);
      unsigned char buf[4];
      if (fread(buf, 1, sizeof(buf), fp) != sizeof(buf)) {
	return MMIO_ERROR_OFFSET;
      }
      uint32_t peri_base = buf[0] << 24 | buf[1] << 16 | buf[2] << 8 | buf[3] << 0;
      uint32_t gpio_base = peri_base + GPIO_BASE_OFFSET;
      fclose(fp);

      int fd = open("/dev/mem", O_RDWR | O_SYNC);
      if (fd == -1) {
	// Error opening /dev/mem.  Probably not running as root.
	return MMIO_ERROR_DEVMEM;
      }
      // Map GPIO memory to location in process space.
      pi_2_mmio_gpio = (uint32_t*)mmap(NULL, GPIO_LENGTH, PROT_READ | PROT_WRITE, MAP_SHARED, fd, gpio_base);
      close(fd);
      if (pi_2_mmio_gpio == MAP_FAILED) {
	// Don't save the result if the memory mapping failed.
	pi_2_mmio_gpio = NULL;
	return MMIO_ERROR_MMAP;
      }
    }
    return MMIO_SUCCESS;
  }



  
} // end namespace RaspberryPi2 