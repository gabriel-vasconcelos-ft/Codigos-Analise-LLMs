#include <stdio.h>

// Utility function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Naive recursive implementation of 0-1 Knapsack
int knapsack(int W, int wt[], int val[], int n) {
    // Base case: If there are no items or knapsack capacity is 0
    if (n == 0 || W == 0)
        return 0;

    // If weight of the nth item is more than knapsack capacity, exclude it
    if (wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1);

    // Return the maximum of two cases:
    // 1. Include the nth item
    // 2. Exclude the nth item
    return max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),
               knapsack(W, wt, val, n - 1));
}

int main() {
    int val[] = {60, 100, 120}; // Values of items
    int wt[] = {10, 20, 30};   // Weights of items
    int W = 50;                // Knapsack capacity
    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value that can be put in the knapsack: %d\n",
           knapsack(W, wt, val, n));
    return 0;
}
