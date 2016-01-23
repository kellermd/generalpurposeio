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
    
    void set_max_priority(void);
    void set_default_priority(void);
    
    static void busy_wait_milliseconds(uint32_t millis);
    static void sleep_milliseconds(uint32_t millis); 
  };
}
#endif // SCHEDULER_H
