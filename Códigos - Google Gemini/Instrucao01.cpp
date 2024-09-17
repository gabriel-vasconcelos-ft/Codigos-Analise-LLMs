int multiply(int x, int y) {
  // Base case: if y is 0, then x * y is simply 0
  if (y == 0) {
    return 0;
  }

  // Recursive case: calculate x * (y - 1) and add x to it
  return x * multiply(x, y - 1);
}

int main() {
  int x, y;

  printf("Enter the value of x: ");
  scanf("%d", &x);

  printf("Enter the value of y: ");
  scanf("%d", &y);

  int product = multiply(x, y);

  printf("The product of %d and %d is %d\n", x, y, product);

  return 0;
}
