#include <stdio.h>
#include <string.h>

int minInsertions(char str[], int l, int h) {
    // Base cases:
    if (l == h) {
        return 0; // Single character, no insertions needed
    } else if (l == h - 1) {
        return (str[l] == str[h]) ? 0 : 1; // Two characters, need 1 insertion if different
    }

    // Check if the first and last characters are the same
    if (str[l] == str[h]) {
        return minInsertions(str, l + 1, h - 1); // Recur for the substring excluding first and last characters
    }

    // If first and last characters are different, consider two possibilities:
    // 1. Insert the first character at the end
    int option1 = minInsertions(str, l + 1, h) + 1;
    // 2. Insert the last character at the beginning
    int option2 = minInsertions(str, l, h - 1) + 1;

    // Return the minimum of the two options
    return (option1 < option2) ? option1 : option2;
}

int main() {
    char str[] = "abcda";
    int n = strlen(str);

    int min_inserts = minInsertions(str, 0, n - 1);

    printf("Minimum number of insertions required to make a palindrome: %d\n", min_inserts);

    return 0;
}
