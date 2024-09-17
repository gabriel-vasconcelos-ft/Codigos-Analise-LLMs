#include <stdio.h>

int maxCostNumber(int cost[], int n, int K) {
    if (K == 0) {
        // If the sum is zero, return 0.
        return 0;
    }
    
    if (n == 0 || K < 0) {
        // If we have exhausted the digits or K is negative, return -1 (invalid).
        return -1;
    }

    // If we take the current digit, what's the maximum value?
    int withCurrent = maxCostNumber(cost, n, K - cost[n - 1]);
    
    // If we skip the current digit, what's the maximum value?
    int withoutCurrent = maxCostNumber(cost, n - 1, K);

    if (withCurrent == -1 && withoutCurrent == -1) {
        // If both options are invalid, return -1.
        return -1;
    } else if (withCurrent == -1) {
        // If only withCurrent is invalid, return withoutCurrent.
        return withoutCurrent;
    } else if (withoutCurrent == -1) {
        // If only withoutCurrent is invalid, return withCurrent with the current digit.
        return withCurrent * 10 + n;
    } else {
        // Return the maximum of withCurrent and withoutCurrent.
        return (withCurrent * 10 + n) > withoutCurrent ? (withCurrent * 10 + n) : withoutCurrent;
    }
}

int main() {
    int cost[] = {3, 1, 4, 1};
    int n = sizeof(cost) / sizeof(cost[0]);
    int K = 7;
    
    int result = maxCostNumber(cost, n, K);
    
    if (result == -1) {
        printf("No valid number can be formed with the given cost and sum.\n");
    } else {
        printf("Maximum number formed with cost %d is: %d\n", K, result);
    }
    
    return 0;
}
