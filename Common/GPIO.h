#ifndef COMMON_GPIO_H
#define COMMON_GPIO_H

#include <string>

namespace Common
{
  class GPIO
  {
  public:
    GPIO();
    GPIO(std::string pin);
    ~GPIO();

    std::string Pin();
    
  protected:
    GPIO(const GPIO& other);
    GPIO& operator=(const GPIO& other);
    bool operator==(const GPIO& other) const;   
    
  private:
    std::string _pin;
  };
}

#endif // GPIO_H
