#include "GPIO.h"
#include "../Common/GPIO.h"

namespace RaspberryPi2 
{
  GPIO::GPIO()
  {

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
  }
  
  const std::string GPIO::GPIO1 = "GPIO1";
  const std::string GPIO::GPIO2 = "GPIO2";
  const std::string GPIO::GPIO3 = "GPIO3";
  const std::string GPIO::GPIO4 = "GPIO4";

} // end namespace RaspberryPi2 