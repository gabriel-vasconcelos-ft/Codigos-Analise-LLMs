#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Utility function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Recursive function to calculate the size of the largest independent set (LIS)
int LIS(struct node* root) {
    if (root == NULL) {
        return 0;
    }

    // Size excluding the current node (consider LIS of subtrees)
    int excl = LIS(root->left) + LIS(root->right);

    // Size including the current node (consider grandchildren)
    int incl = 1;
    if (root->left) {
        incl += LIS(root->left->left) + LIS(root->left->right);
    }
    if (root->right) {
        incl += LIS(root->right->left) + LIS(root->right->right);
    }

    // Return the maximum size (excluding or including current node)
    return max(excl, incl);
}

// Driver program to test the LIS function
int main() {
    struct node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(12);
    root->left->left = newNode(4);
    root->left->right = newNode(10);
    root->right->left = newNode(14);

    printf("Size of the largest independent set: %d\n", LIS(root));

    return 0;
}
