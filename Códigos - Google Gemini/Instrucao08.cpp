#include <stdio.h>
#include <ctype.h>  // For tolower() to handle case-insensitive comparison

int isPalindrome(const char *str, int start, int end) {
    // Base cases:
    if (start >= end) {
        return 1;  // Empty string or single character is a palindrome
    }

    // Handle case-insensitive comparison
    char lowerStart = tolower(str[start]);
    char lowerEnd = tolower(str[end]);

    if (lowerStart != lowerEnd) {
        return 0;  // Characters don't match, not a palindrome
    }

    return isPalindrome(str, start + 1, end - 1);  // Recursively check the middle substring
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    // Remove trailing newline (if present)
    str[strcspn(str, "\n")] = '\0';

    int length = strlen(str);
    int is_palindrome = isPalindrome(str, 0, length - 1);

    if (is_palindrome) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}
