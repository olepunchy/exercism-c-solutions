#include "clock.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hour_from_clock(clock_t clock) {
  int h0 = (clock.text[0] - '0') * 10;
  int h1 = clock.text[1] - '0';

  return abs(h0 + h1) % 24;
}

int minute_from_clock(clock_t clock) {
  int m0 = (clock.text[3] - '0') * 10;
  int m1 = clock.text[4] - '0';

  return abs(m0 + m1) % 60;
}

void update_time_on_clock(clock_t *clock, int change) {
  int h0 = (clock->text[0] - '0') * 10;
  int h1 = clock->text[1] - '0';

  int m0 = (clock->text[3] - '0') * 10;
  int m1 = clock->text[4] - '0';

  int hour = h0 + h1;
  int minute = m0 + m1;

  // Remainder is given to hours
  hour += change / 60;
  printf("Hour: %d\n", hour);
  minute += change % 60;
  printf("Minute: %d\n", minute);

  sprintf(clock->text, "%02d:%02d", hour, minute);
}

clock_t clock_create(int hour, int minute) {
  clock_t clock;

  hour = hour % 24;
  hour = (24 + hour) % 24;
  hour += (minute / 60) % 24;

  minute = minute % 60;

  sprintf(clock.text, "%02d:%02d", hour, minute);

  return clock;
}

clock_t clock_add(clock_t clock, int minute_add) {
  update_time_on_clock(&clock, minute_add);

  return clock;
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
  update_time_on_clock(&clock, minute_subtract);

  return clock;
}

bool clock_is_equal(clock_t a, clock_t b) {
  // Do the thing
  return a.text == b.text;
}
