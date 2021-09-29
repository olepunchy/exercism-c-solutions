#include "isogram.h"
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 256

bool is_isogram(const char phrase[]) {
  if (phrase == NULL) {
    return false;
  }

  char usedLetters[MAX_SIZE] = {0};

  for (size_t index = 0; index < strlen(phrase); index++) {
    if (phrase[index] == '\0' || phrase[index] == '-') {
      continue;
    }

    if (isalpha(phrase[index])) {

      char letter = tolower(phrase[index]);

      char *foundLetter = strchr(usedLetters, letter);

      if (foundLetter != NULL) {
        return false;
      } else {
        size_t position = strlen(usedLetters);
        usedLetters[position] = letter;
      }
    }
  }

  return true;
}
