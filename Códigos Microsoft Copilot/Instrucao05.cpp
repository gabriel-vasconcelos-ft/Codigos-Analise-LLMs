#include <iostream>
#include <string>
#define R 3
#define C 3

using namespace std;

// A recursive function to print all possible sentences that can be formed
// from a list of word list
void printUtil(string arr[R][C], int m, int n, string output[R]) {
    output[m] = arr[m][n];
    if (m == R - 1) {
        for (int i = 0; i < R; i++)
            cout << output[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < C; i++)
        if (arr[m + 1][i] != "")
            printUtil(arr, m + 1, i, output);
}

// A wrapper over printUtil()
void print(string arr[R][C]) {
    string output[R];
    // Print all sentences
    for (int i = 0; i < C; i++)
        if (arr[0][i] != "")
            printUtil(arr, 0, i, output);
}

int main() {
    string arr[R][C] = {{"you", "we"}, {"have", "are"}, {"sleep", "eat", "drink"}};
    print(arr);
    return 0;
}
