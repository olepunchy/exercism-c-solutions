#include "resistor_color.h"
#include <stdlib.h>

int color_code(resistor_band_t color) {
  // Do the thing
  return color;
}

resistor_band_t *colors(void) {
  resistor_band_t *colors =
      malloc((WHITE - BLACK + 1) * sizeof(resistor_band_t));

  for (int color = BLACK; color <= WHITE; color++) {
    colors[color] = color;
  }

  return colors;
}
