#include "space_age.h"

const double EARTH_SECONDS_PER_YEAR = 31557600.0;
const double JUPITER_CONVERSION = EARTH_SECONDS_PER_YEAR * 11.862615;
const double MARS_CONVERSION = EARTH_SECONDS_PER_YEAR * 1.8808158;
const double MERCURY_CONVERSION = EARTH_SECONDS_PER_YEAR * 0.2408467;
const double NEPTUNE_CONVERSION = EARTH_SECONDS_PER_YEAR * 164.79132;
const double SATURN_CONVERSION = EARTH_SECONDS_PER_YEAR * 29.447498;
const double URANUS_CONVERSION = EARTH_SECONDS_PER_YEAR * 84.016846;
const double VENUS_CONVERSION = EARTH_SECONDS_PER_YEAR * 0.61519726;

float age(planet_t planet, int64_t seconds) {
    switch (planet) {
        case EARTH:
            return seconds / EARTH_SECONDS_PER_YEAR;
            break;

        case JUPITER:
            return seconds / JUPITER_CONVERSION;
            break;

        case MARS:
            return seconds / MARS_CONVERSION;
            break;

        case MERCURY:
            return seconds / MERCURY_CONVERSION;
            break;

        case NEPTUNE:
            return seconds / NEPTUNE_CONVERSION;
            break;

        case SATURN:
            return seconds / SATURN_CONVERSION;
            break;

        case URANUS:
            return seconds / URANUS_CONVERSION;
            break;

        case VENUS:
            return seconds / VENUS_CONVERSION;
            break;

        default:
            break;
    }
    return 0.0;
}
