#include "binary.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert(const char *input) {

  size_t index = strlen(input) - 1;
  int result = 0;

  for (unsigned long i = 0; i < strlen(input); i++) {
    // Exaplantion:
    // ASCII character code for 0 is 48
    // ASCII character code for 8 is 56
    // 56 - 48 = 8
    // This pattern can be used to convert an ASCII char to a number 0-9
    if (isalpha(input[i]) || input[i] - '0' >= 2) {
      return INVALID;
    }

    // Left shifting is the same as multiplication.
    result = (input[i] - '0') == 1 ? (result + (1 << index)) : result;
    index--;
  }

  return result;
}
