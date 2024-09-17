#include <stdio.h>

// Recursive function to get x * y
int multiply(int x, int y) {
    // Base case: If y is 0, the product is 0
    if (y == 0) {
        return 0;
    }
    // Recursive case: Multiply x by (y-1) and add x
    return x + multiply(x, y - 1);
}

int main() {
    int x = 5; // Example value for x
    int y = 3; // Example value for y
    int result = multiply(x, y);
    printf("Product of %d and %d is %d\n", x, y, result);
    return 0;
}
