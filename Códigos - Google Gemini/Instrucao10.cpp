#include <stdio.h>

// Function to calculate the greatest common divisor (GCD) of two numbers recursively
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);  // Handle negative remainders for more robust GCD calculation
    }
}

// Function to calculate the LCM of two numbers using the GCD
int lcm(int a, int b) {
    // Handle cases where either number is 0 to avoid division by zero
    if (a == 0 || b == 0) {
        return 0;
    } else {
        return (a * b) / gcd(a, b);  // Use the GCD to efficiently calculate the LCM
    }
}

int main() {
    int num1, num2;

    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    // Ensure both numbers are positive for valid LCM calculation
    if (num1 <= 0 || num2 <= 0) {
        printf("Invalid input. Please enter positive integers.\n");
        return 1;  // Indicate error
    }

    int lcm_value = lcm(num1, num2);
    printf("LCM of %d and %d is %d\n", num1, num2, lcm_value);

    return 0;
}
