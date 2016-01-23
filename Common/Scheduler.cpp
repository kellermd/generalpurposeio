#include <errno.h>
#include <sched.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

#include "Scheduler.h"

namespace Common {
  Scheduler::Scheduler()
  {

  }

  Scheduler::Scheduler(const Scheduler& other)
  {

  }

  Scheduler::~Scheduler()
  {
    set_default_priority();
  }

  Scheduler& Scheduler::operator=(const Scheduler& other)
  {

  }

  bool Scheduler::operator==(const Scheduler& other) const
  {

  }
  
  // --------------------------------------------------------------------------

  void Scheduler::busy_wait_milliseconds(uint32_t millis) 
  {
    // Set delay time period.
    struct timeval deltatime;
    deltatime.tv_sec = millis / 1000;
    deltatime.tv_usec = (millis % 1000) * 1000;
    struct timeval walltime;
    // Get current time and add delay to find end time.
    gettimeofday(&walltime, NULL);
    struct timeval endtime;
    timeradd(&walltime, &deltatime, &endtime);
    // Tight loop to waste time (and CPU) until enough time as elapsed.
    while (timercmp(&walltime, &endtime, <)) {
      gettimeofday(&walltime, NULL);
    }
  }

  void Scheduler::sleep_milliseconds(uint32_t millis) {
    struct timespec sleep;
    sleep.tv_sec = millis / 1000;
    sleep.tv_nsec = (millis % 1000) * 1000000L;
    while (clock_nanosleep(CLOCK_MONOTONIC, 0, &sleep, &sleep) && errno == EINTR);
  }

  void Scheduler::set_max_priority(void) {
    struct sched_param sched;
    memset(&sched, 0, sizeof(sched));
    // Use FIFO scheduler with highest priority for the lowest chance of the kernel context switching.
    sched.sched_priority = sched_get_priority_max(SCHED_FIFO);
    sched_setscheduler(0, SCHED_FIFO, &sched);
  }

  void Scheduler::set_default_priority(void) {
    struct sched_param sched;
    memset(&sched, 0, sizeof(sched));
    // Go back to default scheduler with default 0 priority.
    sched.sched_priority = 0;
    sched_setscheduler(0, SCHED_OTHER, &sched);
  }
  
}