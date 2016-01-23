#include "GPIO.h"


namespace Common
{
  GPIO::GPIO()
  {
  }

  GPIO::GPIO(const GPIO& other)
  {
  }

  GPIO::GPIO(std::string pin) : _pin(pin)
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
  
  std::string GPIO::Pin()
  {
    return this->_pin;
  }
  
  void GPIO::sleep_milliseconds(uint32_t millis) 
  {
    struct timespec sleep;
    sleep.tv_sec = millis / 1000;
    sleep.tv_nsec = (millis % 1000) * 1000000L;
    while (clock_nanosleep(CLOCK_MONOTONIC, 0, &sleep, &sleep) && errno == EINTR);
  }

  void GPIO::busy_wait_milliseconds(uint32_t millis) 
  {
    // Set delay time period.
    struct timeval deltatime;
    deltatime.tv_sec = millis / 1000;
    deltatime.tv_usec = (millis % 1000) * 1000;
    struct timeval walltime;
    // Get current time and add delay to find end time.
    gettimeofday(&walltime, NULL);
    struct timeval endtime;
    timeradd(&walltime, &deltatime, &endtime);
    // Tight loop to waste time (and CPU) until enough time as elapsed.
    while (timercmp(&walltime, &endtime, <)) {
      gettimeofday(&walltime, NULL);
    }
  }  
  // --------------------------------------------------------------------------
  
  PulseCounts::PulseCounts()
  {
    this->_pulseCounts = NULL;
  }
  
  PulseCounts::PulseCounts(int count)
  {
    this->_pulseCounts = new int[count];
    std::fill(this->_pulseCounts, this->_pulseCounts + sizeof(int) * count, 0);
    this->_count = count;
  }

  int * & PulseCounts::rArray()
  {
    return this->_pulseCounts;
  }
  
  int * PulseCounts::Array()
  {
    return this->_pulseCounts;
  }
  
  int PulseCounts::Count()
  {
    return this->_count;
  }
  
} // end namespace Common