#include "acronym.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

const int MAX_ACRONYM_LENGTH = 256;

char *abbreviate(const char *phrase) {

  if (phrase == NULL) {
    return NULL;
  }

  if (strlen(phrase) == 0) {
    return NULL;
  }

  size_t phrase_length = strlen(phrase) - 1;
  size_t acronym_index = 0;
  size_t phrase_index = 0;
  char *acronym = malloc(MAX_ACRONYM_LENGTH * sizeof(char));
  acronym[acronym_index] = toupper(phrase[phrase_index]);

  acronym_index++;
  phrase_index++;

  while (phrase[phrase_index] != '\0') {

    // At the end of the string, add a null terminator.
    if (phrase_index == phrase_length) {
      acronym[acronym_index] = '\0';
      acronym_index++;
      phrase_index++;
      break;
    }

    char letter = phrase[phrase_index];
    char next_letter = phrase[phrase_index + 1];

    // If letter is not an apostrophe or alpha character, but the next one is,
    // found a word boundary and the next charcter is part of the acronym.
    if (letter != '\'' && !isalpha(letter) && isalpha(next_letter)) {
      acronym[acronym_index] = toupper(next_letter);

      acronym_index++;
      phrase_index++;
    }

    phrase_index++;
  }

  return acronym;
}
