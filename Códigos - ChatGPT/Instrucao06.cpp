#include <stdio.h>

// Function to calculate the product of terms in the current term
int product_of_terms(int start, int length) {
    int product = 1;
    for (int i = 0; i < length; ++i) {
        product *= start + i;
    }
    return product;
}

// Recursive function to calculate the sum of the series
int sum_of_series(int current, int N) {
    if (current > N) {
        return 0; // Base case: no more terms to process
    }
    
    // Determine the length of the current term
    int length = (current + 1) / 2;
    
    // Calculate the product for the current term
    int current_product = product_of_terms(current, length);
    
    // Recursively calculate the sum of the remaining terms
    return current_product + sum_of_series(current + length, N);
}

int main() {
    int N;
    printf("Enter the number of terms in the series: ");
    scanf("%d", &N);
    
    // Start calculating the sum from term 1
    int result = sum_of_series(1, N);
    
    // Output the result
    printf("The sum of the series is: %d\n", result);
    
    return 0;
}

