#ifndef COMMON_SCHEDULER_H
#define COMMON_SCHEDULER_H

#include <stdint.h>

namespace Common
{
  class Scheduler
  {
  public:
    Scheduler();
    Scheduler(const Scheduler& other);
    virtual ~Scheduler();
    Scheduler& operator=(const Scheduler& other);
    bool operator==(const Scheduler& other) const;
    
    void SetMaxPriority(void);
    void SetDefaultPriority(void);
    
    static void BusyWait(uint32_t millis);
    static void Sleep(uint32_t millis); 
  };
}
#endif // SCHEDULER_H
