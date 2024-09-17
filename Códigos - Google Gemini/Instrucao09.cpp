#include <stdio.h>

// Utility function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive function to solve the 0-1 Knapsack problem
int knapsack(int W, int wt[], int val[], int n) {
    // Base Cases
    if (n == 0 || W == 0) {
        return 0;  // No items or zero capacity
    }

    // If weight of the nth item is more than Knapsack capacity W,
    // then this item cannot be included in the optimal solution
    if (wt[n - 1] > W) {
        return knapsack(W, wt, val, n - 1);  // Exclude the nth item
    }

    // Return the maximum of two cases:
    // (1) nth item included  (2) not included
    return max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),
               knapsack(W, wt, val, n - 1));
}

// Driver program to test above function
int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value = %d\n", knapsack(W, wt, val, n));

    return 0;
}
