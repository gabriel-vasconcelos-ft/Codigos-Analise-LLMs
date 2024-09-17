#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Utility function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Utility function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive function to find the size of the largest independent set
int largestIndependentSet(Node* root) {
    // Base case: If the tree is empty, the size of the LIS is 0
    if (root == NULL) {
        return 0;
    }

    // Case 1: Exclude the current node
    int size_excluding_current = largestIndependentSet(root->left) + largestIndependentSet(root->right);

    // Case 2: Include the current node
    int size_including_current = 1; // Current node is included
    if (root->left != NULL) {
        size_including_current += largestIndependentSet(root->left->left) + largestIndependentSet(root->left->right);
    }
    if (root->right != NULL) {
        size_including_current += largestIndependentSet(root->right->left) + largestIndependentSet(root->right->right);
    }

    // Return the maximum of the two cases
    return max(size_excluding_current, size_including_current);
}

// Driver program to test the above functions
int main() {
    // Construct the tree given in the example diagram
    // Example Tree:
    //         1
    //        / \
    //       2   3
    //      / \   / \
    //     4   5 6   7

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Find and print the size of the largest independent set
    int lisSize = largestIndependentSet(root);
    printf("Size of the largest independent set is %d\n", lisSize);

    // Free allocated memory (not shown for simplicity, but it's a good practice to free memory)
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
