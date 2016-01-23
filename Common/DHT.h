#ifndef DHT_H
#define DHT_H

#include "GPIO.h"

// Define errors and return values.
#define DHT_ERROR_TIMEOUT -1
#define DHT_ERROR_CHECKSUM -2
#define DHT_ERROR_ARGUMENT -3
#define DHT_ERROR_GPIO -4
#define DHT_SUCCESS 0

// Define sensor types.
#define DHT11 11
#define DHT22 22
#define AM2302 22

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
    
    int dht_read(Common::GPIO & gpio, int type, int gpio_base, int gpio_number, float* humidity, float* temperature);
    
  };
}
#endif // DHT_H
