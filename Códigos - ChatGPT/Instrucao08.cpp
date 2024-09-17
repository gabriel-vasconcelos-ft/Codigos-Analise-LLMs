#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Recursive function to check if a substring str[s..e] is a palindrome
bool isPalindrome(char str[], int s, int e) {
    // Base cases
    if (s >= e) {
        return true;  // Single character or no characters left
    }
    if (str[s] != str[e]) {
        return false; // Characters do not match
    }
    // Recursive case: check the middle substring
    return isPalindrome(str, s + 1, e - 1);
}

// Function to check if the entire string is a palindrome
bool checkPalindrome(char str[]) {
    int len = strlen(str);
    return isPalindrome(str, 0, len - 1);
}

int main() {
    char str[100];

    // Get input from user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;

    // Check if the string is a palindrome
    if (checkPalindrome(str)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}

