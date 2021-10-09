#include "acronym.h"
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Updated after code review reply by G. Sliepen

char *abbreviate(const char *phrase) {
  // Production code should call assert() here
  // For exercism tests, instead return NULL
  if (phrase == NULL || strlen(phrase) == 0) {
    return NULL;
  }

  // Estimate the size of the acronym to be no more than
  // half the length of the phrase plus null terminator.
  char *acronym = malloc(strlen(phrase) / 2 + 1);
  // Verify that the memory allocation worked.
  if (!acronym) {
    return NULL;
  }

  char previous = ' ';
  size_t length = 0;

  for (size_t index = 0; phrase[index]; index++) {
    char current = phrase[index];

    if (previous != '\'' && !isalpha(previous) && isalpha(current)) {
      acronym[length++] = toupper(current);
    }

    previous = current;
  }

  // Null terminate the string
  acronym[length++] = '\0';
  // Resize acronym to the number of bytes used
  return realloc(acronym, length);
}
