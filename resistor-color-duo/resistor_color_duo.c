#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t *colors) {
  // Do the thing
  uint16_t base = colors[0] * 10;
  uint16_t second = colors[1];

  return base + second;
}
