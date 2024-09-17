#include <stdio.h>

// Utility function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive function to solve the 0/1 Knapsack problem
// W is the maximum capacity of the knapsack
// weights[] and values[] are arrays containing the weights and values of the items
// n is the number of items
int knapsack(int weights[], int values[], int W, int n) {
    // Base Case: If no items are left or capacity is 0
    if (n == 0 || W == 0)
        return 0;
    
    // If the weight of the nth item is more than the Knapsack capacity W,
    // it cannot be included in the optimal solution
    if (weights[n-1] > W)
        return knapsack(weights, values, W, n-1);

    // Return the maximum of two cases:
    // 1. nth item included
    // 2. nth item not included
    int includeItem = values[n-1] + knapsack(weights, values, W - weights[n-1], n-1);
    int excludeItem = knapsack(weights, values, W, n-1);
    
    return max(includeItem, excludeItem);
}

// Driver program to test the knapsack function
int main() {
    int values[] = {60, 100, 120};  // Values of the items
    int weights[] = {10, 20, 30};   // Weights of the items
    int W = 50;  // Maximum weight capacity of the knapsack
    int n = sizeof(values) / sizeof(values[0]);  // Number of items
    
    printf("Maximum value that can be put in the knapsack is %d\n", knapsack(weights, values, W, n));
    
    return 0;
}
