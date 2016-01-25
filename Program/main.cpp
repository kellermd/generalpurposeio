#include <iostream>
#include "../Common/GPIO.h"
#include "../Common/Scheduler.h"
#include "../Common/DHT.h"
#include "../Common/HCSR04.h"
#include "../RaspberryPi2/GPIO.h"

#include <string>
#include <memory>

#include <cxxabi.h>
#include <cstdlib>

void GPIOTest()
{
    try
    {
	Common::GPIO * gpio = new RaspberryPi2::GPIO(RaspberryPi2::GPIO::GPIO4);
	gpio->SetOutput();
	gpio->SetHigh(20);
	gpio->SetLow(20);
	gpio->SetInput();
	
	int maxCount = 10000;
	int count = 0;
	while (gpio->GetValue() && count < maxCount)
	{
	  count++;
	}
	std::cout << "GPIO read high" << count << " times.\r\n";
	
	count = 0;
	while (!gpio->GetValue() && count < maxCount)
	{
	  count++;
	}
	std::cout << "GPIO read low" << count << " times.\r\n";
    }
    catch (const std::exception& ex)  
    {
      std::cout << "std::exception returned. " << ex.what();
    }
}

void TemperatureTest()
{
    try
    {
      std::auto_ptr<Common::GPIO> gp(new RaspberryPi2::GPIO(RaspberryPi2::GPIO::GPIO4));
      std::cout << "Hello, GPIO! " << gp->Pin() << std::endl;

      Common::DHT dht;
      dht.ReadSensor(*gp, Common::DHT::DHT22); 

      std::cout << "Caller received. Temp:" 
                << dht.Temperature() << "C (" << (dht.Temperature() * 9.0f / 5.0f) + 32 << "F)" 
                << "; Humidity:" << dht.Humidity();

    }
    catch (const std::exception& ex)  
    {
      std::cout << "std::exception returned. " << ex.what();
    }
}

void DistanceTest()
{
    try
    {
      std::auto_ptr<Common::GPIO> trig(new RaspberryPi2::GPIO(RaspberryPi2::GPIO::GPI23));
      std::cout << "Hello, trig! " << trig->Pin() << std::endl;

      std::auto_ptr<Common::GPIO> echo(new RaspberryPi2::GPIO(RaspberryPi2::GPIO::GPI24));
      std::cout << "Hello, echo! " << echo->Pin() << std::endl;

      Common::HCSR04 distanceSensor(*trig, *echo);
      distanceSensor.ReadSensor();

      std::cout << "Distance sensor test done.  Distance:" << distanceSensor.Distance() << "\n";

    }
    catch (const std::exception& ex)  
    {
      std::cout << "std::exception returned. " << ex.what();
    }
}

int main(int argc, char **argv) {
 
    try
    {
      DistanceTest();
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
    return 0;
}
