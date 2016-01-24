#ifndef DHT_H
#define DHT_H

#include "GPIO.h"
#include <string>

// Define errors and return values.
#define DHT_ERROR_TIMEOUT -1
#define DHT_ERROR_CHECKSUM -2
#define DHT_ERROR_ARGUMENT -3
#define DHT_ERROR_GPIO -4
#define DHT_SUCCESS 0

// Define sensor types.
//#define DHT11 11
//#define DHT22 22
//#define AM2302 22

namespace Common
{
  class DHT
  {
    public:
    DHT();
    DHT(GPIO & gpio);
    DHT(const DHT& other);
    ~DHT();
    DHT& operator=(const DHT& other);
    bool operator==(const DHT& other) const;
    
    void ReadSensor(Common::GPIO & gpio, std::string type);
    
    float Humidity();
    float Temperature();
    
    // Constants
    const static std::string DHT11;
    const static std::string DHT22;
    const static std::string AM2302;

  protected:
    
  private:
    float _humidity;
    float _temperature;
  };
}
#endif // DHT_H
