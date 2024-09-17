#include <stdio.h>

int multiply(int x, int y) {
    if (y == 0) {
        return 0;
    } else if (y > 0) {
        return x + multiply(x, y - 1);
    } else {
        return -multiply(x, -y);
    }
}

int main() {
    int x = 5;
    int y = 4;

    int result = multiply(x, y);
    printf("%d * %d = %d\n", x, y, result);

    return 0;
}