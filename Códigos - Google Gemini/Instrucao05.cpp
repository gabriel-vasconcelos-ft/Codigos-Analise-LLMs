#include <stdio.h>
#include <string.h>

void printSentences(char *wordLists[][20], int currentList, int sentenceLength, char *currentSentence) {
  // Base case: If all word lists are processed, print the sentence
  if (currentList >= strlen(wordLists[0][0])) {
    printf("%s\n", currentSentence);
    return;
  }

  // Loop through each word in the current word list
  for (int i = 0; wordLists[currentList][i] != '\0'; i++) {
    // Append the word to the current sentence
    strcat(currentSentence, wordLists[currentList][i]);
    strcat(currentSentence, " ");

    // Recursively call for the next word list with updated sentence
    printSentences(wordLists, currentList + 1, sentenceLength + strlen(wordLists[currentList][i]) + 1, currentSentence);

    // Backtrack: Remove the appended word and space for the next iteration
    currentSentence[sentenceLength] = '\0';
  }
}

int main() {
  char wordLists[][20] = {
    {"The", "A"},
    {"quick", "brown"},
    {"fox", "jumps"},
    {"over", "lazy"},
    {"dog", "."}
  };

  int numLists = sizeof(wordLists) / sizeof(wordLists[0]);
  char currentSentence[100] = "";

  printf("All possible sentences:\n");
  printSentences(wordLists, 0, 0, currentSentence);

  return 0;
}
