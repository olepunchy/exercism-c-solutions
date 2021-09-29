#include "gigasecond.h"
#include <time.h>

time_t gigasecond_after(time_t time) {
  // Do the thing
  return time + 1000000000;
}

/* time_t construct_date(int year, int month, int day, int hour, int minute, */
/*                       int second) { */

/*   struct tm time = {.tm_year = year, */
/*                     .tm_mon = month, */
/*                     .tm_mday = day, */
/*                     .tm_hour = hour, */
/*                     .tm_min = minute, */
/*                     .tm_sec = second}; */

/*   time_t result = mktime(&time); */

/*   return result; */
/* } */
