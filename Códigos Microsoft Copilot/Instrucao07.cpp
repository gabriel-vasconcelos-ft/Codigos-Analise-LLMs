#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Utility function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to calculate the size of the largest independent set
int largestIndependentSet(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    // Calculate size excluding the current node
    int excl = largestIndependentSet(root->left) + largestIndependentSet(root->right);

    // Calculate size including the current node
    int incl = 1;
    if (root->left)
        incl += largestIndependentSet(root->left->left) + largestIndependentSet(root->left->right);
    if (root->right)
        incl += largestIndependentSet(root->right->left) + largestIndependentSet(root->right->right);

    // Return the maximum of the two sizes
    return (excl > incl) ? excl : incl;
}

// Driver program to test the above functions
int main() {
    struct TreeNode* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->right = createNode(60);

    printf("Size of the largest independent set: %d\n", largestIndependentSet(root));

    // Clean up memory (optional)
    // You can add more nodes to the tree as needed

    return 0;
}

