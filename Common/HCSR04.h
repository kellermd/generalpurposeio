#ifndef HCSR04_H
#define HCSR04_H

#include "GPIO.h"

#include <string>

namespace Common
{
  class HCSR04
  {
  public:
      HCSR04(Common::GPIO & trig, Common::GPIO & echo);
      HCSR04(const HCSR04& other);
      HCSR04& operator=(const HCSR04& other);
      bool operator==(const HCSR04& other) const;   
      virtual ~HCSR04();
      
      void ReadSensor();
      
      double Distance();
      
  protected:    
      HCSR04();
      
  private:
    Common::GPIO * _trig;
    Common::GPIO * _echo;
    double         _distance;
  };
}

#endif // HCSR04_H
