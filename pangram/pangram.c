#include "pangram.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

const char *alphabet = "abcdefghijklmnopqrstuvwxyz";

char *resize_array(char *array, int length) {
  // Resize the array and return
  return realloc(array, length);
}

bool is_pangram(const char *sentence) {
  // Return NULL if the sentence is empty or NULL to satisfy tests
  // Use assert() in production code.
  if (sentence == NULL || strlen(sentence) == 0) {
    return NULL;
  }

  char *used_letters = malloc(strlen(alphabet) * sizeof(char) + 1);
  size_t length = 0;

  for (size_t index = 0; sentence[index]; index++) {
    char letter = tolower(sentence[index]);

    // If we haven't seen this letter before, add it to used_letters
    if (isalpha(letter) && strchr(used_letters, letter) == NULL) {
      used_letters[length++] = letter;
    }
  }

  used_letters[length++] = '\0';

  used_letters = resize_array(used_letters, length);

  return strlen(used_letters) == strlen(alphabet);
}
