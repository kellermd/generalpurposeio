#ifndef COMMON_GPIO_H
#define COMMON_GPIO_H

#include <string>
#include <list>
#include <time.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>
#include <sys/time.h>

namespace Common
{
  class PulseCounts 
  {
  public:
    PulseCounts(int count);
    int * & rArray();
    int * Array();
    int Count();
    
  protected:
    PulseCounts();
    
  private:
    int * _pulseCounts;
    int _count;
  };

  // --------------------------------------------------------------------------

  class GPIO
  {
  public:
    GPIO();
    GPIO(std::string pin);
    GPIO(const GPIO& other);
    GPIO& operator=(const GPIO& other);
    bool operator==(const GPIO& other) const;   
    virtual ~GPIO();

    std::string Pin();
    
    // Methods to override
    virtual int Init()=0;
    virtual void SetOutput()=0;
    virtual void SetInput()=0;
    virtual void SetHigh(int millis)=0;
    virtual void SetLow (int millis)=0;
    virtual int  GetValue()=0;
    virtual void ReadPulseCounts(Common::PulseCounts & pulseCountsObject, int maxCount)=0;
    
  protected:
    void sleep_milliseconds(uint32_t millis);
    void busy_wait_milliseconds(uint32_t millis);
    
  private:
    std::string _pin;
  };
  
} // end namespace Common

#endif // GPIO_H
