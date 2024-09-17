#include <stdio.h>

// Function to calculate the product of a range of numbers (inclusive)
int product(int start, int end) {
    if (start == end) {
        return start; // Base case: product of one number is itself
    } else {
        return start * product(start + 1, end); // Recursive call to calculate product
    }
}

// Function to calculate the sum of the series f(n) using recursion
int f(int current, int n) {
    if (current > n) {
        return 0; // Base case: sum becomes 0 when exceeding the number of terms
    } else if (current == 1) {
        return 1; // Base case: f(1) = 1
    } else {
        // Calculate product of terms from current to current + 2
        int term_product = product(current, current + 2);
        // Recursive call to add current term's product and sum for remaining terms
        return term_product + f(current + 3, n);
    }
}

int main() {
    int num_terms;

    printf("Enter the number of terms in the series: ");
    scanf("%d", &num_terms);

    int sum = f(1, num_terms); // Start from current=1 and calculate sum for n terms

    printf("The sum of the series f(%d) is: %d\n", num_terms, sum);

    return 0;
}
