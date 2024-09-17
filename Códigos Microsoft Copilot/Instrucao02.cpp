#include <stdio.h>
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int findMinInsertions(char str[], int l, int h) {
    if (l >= h) {
        return 0; // Base case: empty string or single character
    }

    if (str[l] == str[h]) {
        return findMinInsertions(str, l + 1, h - 1);
    } else {
        return 1 + min(findMinInsertions(str, l, h - 1), findMinInsertions(str, l + 1, h));
    }
}

int main() {
    char str[] = "geeks";
    printf("Minimum insertions: %d\n", findMinInsertions(str, 0, strlen(str) - 1));
    return 0;
}
