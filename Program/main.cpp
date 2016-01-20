#include <iostream>
#include "../Common/GPIO.h"
#include "../RaspberryPi2/GPIO.h"
#include <string>

//using namespace RaspberryPi2;

int main(int argc, char **argv) {
 
    std::string pin = "R7";
    Common::GPIO * gpio = new RaspberryPi2::GPIO(RaspberryPi2::GPIO::GPIO1);
    //new Common::GPIO(RaspberryPi2::GPIO::GPIO4);
    //gpio->rPin() = RaspberryPi2::GPIO::GPIO4;
    std::cout << "Hello, world! " << gpio->Pin() << std::endl;
    delete gpio;
    
    return 0;
}
