#include <stdio.h>

// Function prototype declarations
int gcd(int a, int b);   // Recursive function to return GCD of a and b
int lcm(int a, int b);   // Function to return LCM of two numbers

// Recursive function to return GCD of a and b
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Function to return LCM of two numbers
int lcm(int a, int b) {
    // LCM can be calculated using the formula: lcm(a, b) = abs(a*b) / gcd(a, b)
    return (a * b) / gcd(a, b);
}

// Driver program to test above functions
int main() {
    int num1, num2;

    // Input two numbers from user
    printf("Enter two numbers to find their LCM:\n");
    scanf("%d %d", &num1, &num2);

    // Make sure the numbers are positive
    if (num1 <= 0 || num2 <= 0) {
        printf("Please enter positive numbers.\n");
        return 1;
    }

    // Call the LCM function and print the result
    printf("The LCM of %d and %d is %d\n", num1, num2, lcm(num1, num2));

    return 0;
}
