#ifndef RASPBERRYPI2_GPIO_H
#define RASPBERRYPI2_GPIO_H

#include "../Common/GPIO.h"
#include <string>

namespace RaspberryPi2
{
  class GPIO : public Common::GPIO
  {
  public:
    // Constructors/destructors
    GPIO();
    GPIO(std::string pin);
    ~GPIO();

    // Constants
    const static std::string GPIO1;
    const static std::string GPIO2;
    const static std::string GPIO3;
    const static std::string GPIO4;
    
  protected:
    GPIO(const GPIO& other);
    GPIO& operator=(const GPIO& other);
    bool operator==(const GPIO& other) const;
    protected:
    GPIO(const Common::GPIO& other);

  private:
  };
}

#endif // GPIO_H
