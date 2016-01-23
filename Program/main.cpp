#include <iostream>
#include "../Common/GPIO.h"
#include "../Common/Scheduler.h"
#include "../Common/DHT.h"
#include "../RaspberryPi2/GPIO.h"
#include <string>

#include <cxxabi.h>
#include <cstdlib>

int main(int argc, char **argv) {
 
    try
    {
      std::string pin = "R7";
      Common::GPIO * gpio = new RaspberryPi2::GPIO(RaspberryPi2::GPIO::GPIO2);
      //new Common::GPIO(RaspberryPi2::GPIO::GPIO4);
      //gpio->rPin() = RaspberryPi2::GPIO::GPIO4;
      std::cout << "Hello, world! " << gpio->Pin() << std::endl;

      Common::DHT & dht = *(new Common::DHT());
      
      float humidity;
      float temperature;
      dht.dht_read(*gpio, 0 /*int type*/, 0x3000/*int gpio_base*/, 0/*int gpio_number*/, &humidity, &temperature);
      
      gpio->SetInput();
      gpio->SetOutput();
      gpio->SetHigh(20);
      gpio->SetLow(20);

      delete gpio;
    }
    catch (const std::exception& ex)  
    {
      std::cout << "std::exception returned. " << ex.what();
    }
    catch (int e)
    {
      std::cout << "Error #" << e;
    }
    catch (...)
    {
      std::cout << "Unknown exception caught";
      std::cout << "\nUnknown exception type: '" << __cxxabiv1::__cxa_current_exception_type()->name() << "'" << std::endl;
    }
    
    Common::Scheduler scheduler;
    scheduler.set_max_priority();
    
    
    return 0;
}
