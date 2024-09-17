#include <stdio.h>
#include <stdlib.h>

// A binary tree node has data, pointer to left child, and a pointer to right child
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to find the maximum of two integers
int max(int x, int y) {
    return (x > y) ? x : y;
}

// Recursive function to calculate the size of the largest independent set
int LISS(struct Node* root) {
    if (root == NULL)
        return 0;

    // Calculate size excluding the current node
    int size_excl = LISS(root->left) + LISS(root->right);

    // Calculate size including the current node
    int size_incl = 1;
    if (root->left)
        size_incl += LISS(root->left->left) + LISS(root->left->right);
    if (root->right)
        size_incl += LISS(root->right->left) + LISS(root->right->right);

    // Return the maximum of two sizes
    return max(size_incl, size_excl);
}

// Utility function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main() {
    // Construct the tree given in the example diagram
    struct Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    // Calculate and print the size of the largest independent set
    printf("Size of the Largest Independent Set is %d\n", LISS(root));

    return 0;
}

