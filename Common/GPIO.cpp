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
} // end namespace Common