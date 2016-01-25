#ifndef RASPBERRYPI2_GPIO_H
#define RASPBERRYPI2_GPIO_H

#include "../Common/GPIO.h"
#include <string>
#include <stdint.h>

namespace RaspberryPi2
{
  class GPIO : public Common::GPIO
  {
  public:
    // Constructors/destructors
    GPIO(std::string pin);
    virtual ~GPIO();

    // Overridden methods
    int Init();
    void SetOutput();
    void SetInput();
    void SetHigh(int millis);
    void SetLow (int millis);
    int  GetValue();
    void ReadPulseCounts(Common::PulseCounts & pulseCountsObject, int maxCount);

    // Constants
    const static std::string GPIO1;
    const static std::string GPIO2;
    const static std::string GPIO3;
    const static std::string GPIO4;
    const static std::string GPI23;
    const static std::string GPI24;

    typedef enum tagGPIO 
    {
      _GPIO1 = 1,
      _GPIO2 = 2
    }
    GPIOTypeEnum;
    
  protected:
    // Constructors/destructors
    GPIO();
    GPIO(const GPIO& other);
    GPIO(const Common::GPIO& other);
    GPIO& operator=(const GPIO& other);
    bool operator==(const GPIO& other) const;

  private:
    int _gpio_number;

    void SetGPIONumber(std::string pin);
    
    static const int MMIO_SUCCESS = 0;
    static const int MMIO_ERROR_DEVMEM = -1;
    static const int MMIO_ERROR_MMAP = -2;
    static const int MMIO_ERROR_OFFSET = -3;
    static int pi_2_mmio_init(void);
    static volatile uint32_t* pi_2_mmio_gpio;
    
    static inline void pi_2_mmio_set_input(const int gpio_number) {
      // Set GPIO register to 000 for specified GPIO number.
      *(pi_2_mmio_gpio+((gpio_number)/10)) &= ~(7<<(((gpio_number)%10)*3));
    }

    static inline void pi_2_mmio_set_output(const int gpio_number) {
      // First set to 000 using input function.
      pi_2_mmio_set_input(gpio_number);
      // Next set bit 0 to 1 to set output.
      *(pi_2_mmio_gpio+((gpio_number)/10)) |=  (1<<(((gpio_number)%10)*3));
    }

    static inline void pi_2_mmio_set_high(const int gpio_number) {
      *(pi_2_mmio_gpio+7) = 1 << gpio_number;
    }

    static inline void pi_2_mmio_set_low(const int gpio_number) {
      *(pi_2_mmio_gpio+10) = 1 << gpio_number;
    }

    static inline uint32_t pi_2_mmio_input(const int gpio_number) {
      return *(pi_2_mmio_gpio+13) & (1 << gpio_number);
    }    
  };
}

#endif // GPIO_H
