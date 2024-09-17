#include <stdio.h>
#include <string.h>

void printAllSentences(char* words[], int n, char* sentence) {
    if (n == 0) {
        // No more words to consider, print the sentence
        printf("%s\n", sentence);
        return;
    }

    for (int i = 0; i < n; i++) {
        char newSentence[1000]; // Adjust the size as needed
        strcpy(newSentence, sentence);
        if (strlen(sentence) > 0) {
            strcat(newSentence, " ");
        }
        strcat(newSentence, words[i]);
        printAllSentences(words, n - 1, newSentence);
    }
}

int main() {
    char* wordList[] = {"This", "is", "an", "example"};
    int n = sizeof(wordList) / sizeof(wordList[0]);
    char initialSentence[1000] = ""; // Initialize with an empty string

    printAllSentences(wordList, n, initialSentence);

    return 0;
}
