#include "acronym.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *abbreviate(const char *phrase) {

  // Return NULL for NULL or empty phrase
  if (phrase == NULL || strlen(phrase) == 0) {
    return NULL;
  }

  size_t phrase_length = strlen(phrase) - 1;
  size_t acronym_index = 0;
  size_t phrase_index = 0;

  // The acronym will not be longer than the phrase length.
  char *acronym = malloc(phrase_length * sizeof(char));

  // The first letter of the phrase is the first initial in the acronym.
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
