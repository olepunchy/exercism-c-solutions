#include "difference_of_squares.h"

#include <stdio.h>

unsigned int sum_of_squares(unsigned int number) {
    unsigned int total = 0;

    for (size_t counter = 0; counter <= number; counter++) {
        total += counter * counter;
    }

    return total;
}

unsigned int square_of_sum(unsigned int number) {
    unsigned int total = 0;

    for (size_t counter = 0; counter <= number; counter++) {
        total += counter;
    }

    return total * total;
}

unsigned int difference_of_squares(unsigned int number) {
    // Do the thing
    return square_of_sum(number) - sum_of_squares(number);
}
