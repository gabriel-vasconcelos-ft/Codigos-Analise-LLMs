#include <stdio.h>

int get_middle_index(int arr[], int low, int high) {
  // Base case: Empty or single element array
  if (low >= high) {
    return -1; // Indicate invalid partition (empty or single element)
  }

  // Calculate middle index for even or odd sized array
  int mid = low + (high - low) / 2;
  return mid;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  int middle_index = get_middle_index(arr, 0, n - 1);

  if (middle_index == -1) {
    printf("Invalid partition: Array is empty or has a single element\n");
  } else {
    printf("Middle index for equal partition: %d\n", middle_index);
  }

  return 0;
}

