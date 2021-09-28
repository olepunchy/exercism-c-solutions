#ifndef SPACE_AGE_H
#define SPACE_AGE_H

#include <stdint.h>

typedef enum planet {
    EARTH,
    JUPITER,
    MARS,
    MERCURY,
    NEPTUNE,
    SATURN,
    URANUS,
    VENUS,
} planet_t;

float age(planet_t planet, int64_t seconds);

#endif
