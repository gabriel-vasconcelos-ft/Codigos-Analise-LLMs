#include <stdio.h>

// Function to get the cost of a digit
int getCost(int digit) {
  // Replace this with your actual cost logic for each digit
  // (e.g., an array to store costs)
  return digit; // Example: Cost of each digit is its value
}

// Recursive function to find the maximum number
char* findMaxNumber(int cost[], int n, int k) {
  // Base case: If there are no digits or remaining cost is 0, return empty string
  if (n == 0 || k == 0) {
    return "";
  }

  // Check if current digit cost is less than or equal to remaining cost
  int currentDigitCost = getCost(n - 1);
  if (currentDigitCost <= k) {
    // Include the digit and recur for remaining cost
    char* remaining = findMaxNumber(cost, n - 1, k - currentDigitCost);
    char* result = (char*)malloc(sizeof(char) * 2); // Allocate space for digit and null terminator
    result[0] = n - 1 + '0'; // Convert digit to character
    result[1] = '\0';
    strcat(result, remaining); // Append remaining digits
    return result;
  } else {
    // Exclude the digit and recur with remaining digits
    return findMaxNumber(cost, n - 1, k);
  }
}

int main() {
  int cost[] = {3, 1, 4, 1, 5, 9, 2, 6, 5}; // Example cost array
  int n = sizeof(cost) / sizeof(cost[0]); // Number of digits
  int k = 15; // Target cost

  char* maxNumber = findMaxNumber(cost, n, k);

  if (maxNumber[0] == '\0') {
    printf("No number possible with cost %d\n", k);
  } else {
    printf("Maximum number formed: %s\n", maxNumber);
  }

  // Free the allocated memory (optional, but good practice)
  free(maxNumber);

  return 0;
}
