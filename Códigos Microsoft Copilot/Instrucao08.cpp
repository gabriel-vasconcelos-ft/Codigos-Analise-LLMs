#include <stdio.h>
#include <string.h>

// Recursive function to check if a string is a palindrome
int isPalindrome(char str[], int start, int end) {
    // Base case: If there is only one character or none left
    if (start >= end)
        return 1;

    // Compare the first and last characters
    if (str[start] != str[end])
        return 0;

    // Recurse on the substring excluding the first and last characters
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char inputString[] = "malayalam"; // Example input string

    // Call the isPalindrome function
    if (isPalindrome(inputString, 0, strlen(inputString) - 1))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}
