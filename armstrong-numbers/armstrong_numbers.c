#include "armstrong_numbers.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 256

bool is_armstrong_number(int candidate) {

  char candidateString[STRING_SIZE] = {0};
  sprintf(candidateString, "%d", candidate);

  int result = 0;
  int power = (int)strlen(candidateString);

  for (int index = 0; index <= power; index++) {
    char numberChar = candidateString[index];
    int number = atoi(&numberChar);
    int raisedNumber = (int)pow((double)number, (double)power);
    result += raisedNumber;
  }

  return result == candidate;
}
