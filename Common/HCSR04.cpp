#include "HCSR04.h"
#include "GPIO.h"
#include "Scheduler.h"
#include <math.h>
#include <iostream>

namespace Common
{
  HCSR04::HCSR04()
  {
  }
  
  HCSR04::HCSR04(Common::GPIO & trig, Common::GPIO & echo) : _distance(0.0f), _trig(&trig), _echo(&echo)
  {
  }
  
  HCSR04::HCSR04(const HCSR04& other)
  {
  }

  HCSR04& HCSR04::operator=(const HCSR04& other)
  {
  }

  bool HCSR04::operator==(const HCSR04& other) const
  {
  }
   
  HCSR04::~HCSR04()
  {
  }
  
  // --------------------------------------------------------------------------
  
  double HCSR04::Distance()
  {
    return this->_distance;
  }
  
  // --------------------------------------------------------------------------

  void HCSR04::ReadSensor()
  {
    Scheduler scheduler;
    
    GPIO & trig = *(this->_trig);
    GPIO & echo = *(this->_echo);
    
    // Setup
    trig.SetOutput();
    echo.SetInput();
    
    // Wait for sensor to settle
    scheduler.Sleep(2000);

    struct timeval pulse_start;
    struct timeval pulse_end;
    struct timeval pulse_duration;

    // Calculate how much time is used to get value from the GPIO object
    gettimeofday(&pulse_start, NULL);
    for (int i=0; i < 1000000; i++)
    {
      echo.GetValue();
    }
    gettimeofday(&pulse_end, NULL);
    timersub(&pulse_end, &pulse_start, &pulse_duration);
    std::cout << ((double)pulse_duration.tv_sec + ((double)pulse_duration.tv_usec / 1000000.0f)) << " seconds\n";
    
    // Send pulse to trig
    trig.SetHigh(1);
    trig.SetLow(0);
    

    // Wait for pulse on echo to start
    while (echo.GetValue() == 0)
    {
    }
    gettimeofday(&pulse_start, NULL);
    
    // Wait for pulse on echo to end
    while (echo.GetValue() != 0);
    {
    }
    gettimeofday(&pulse_end, NULL);
    
    timersub(&pulse_end, &pulse_start, &pulse_duration);	
    _distance = ((double)pulse_duration.tv_sec + ((double)pulse_duration.tv_usec / 1000000.0f)) * 17150.0f;
 }
  
} // end namespace Common