#include <stdio.h>
#include <string.h>

int minInsertionsToMakePalindrome(char str[], int left, int right) {
    if (left >= right) {
        return 0;
    }

    if (str[left] == str[right]) {
        return minInsertionsToMakePalindrome(str, left + 1, right - 1);
    } else {
        int insertLeft = minInsertionsToMakePalindrome(str, left, right - 1);
        int insertRight = minInsertionsToMakePalindrome(str, left + 1, right);
        return 1 + (insertLeft < insertRight ? insertLeft : insertRight);
    }
}

int main() {
    char str[] = "abcde";
    int n = strlen(str);
    int minInsertions = minInsertionsToMakePalindrome(str, 0, n - 1);
    
    printf("Minimum number of insertions to make the string a palindrome: %d\n", minInsertions);
    return 0;
}
