#include <stdio.h>
#include <string.h>

// Given cost of digits from 1 to 9
int arr[] = {3, 12, 9, 5, 3, 4, 6, 5, 10};
int N = 9; // Number of digits

// Recursive function to find the largest number with sum of cost equal to K
char* recursion(int i, int K) {
    // Base cases
    if (K == 0) {
        char* result = (char*)malloc(2);
        result[0] = '\0';
        return result;
    }
    if (K < 0 || i == N) {
        char* result = (char*)malloc(2);
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    // Include the current digit
    char* include = recursion(0, K - arr[i]);
    char* result = (char*)malloc(strlen(include) + 2);
    sprintf(result, "%d%s", i + 1, include);
    free(include);

    // Exclude the current digit
    char* exclude = recursion(i + 1, K - arr[i]);
    if (strcmp(result, exclude) < 0) {
        strcpy(result, exclude);
    }
    free(exclude);

    return result;
}

int main() {
    int K = 14; // Desired sum of cost
    char* largestNumber = recursion(0, K);
    printf("Largest number with cost %d: %s\n", K, largestNumber);
    free(largestNumber);
    return 0;
}
