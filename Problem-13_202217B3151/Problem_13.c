#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
struct node {
    int data;
    struct node *left_child;
    struct node *right_child;
};

// Function to create a new node
struct node* new_node(int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left_child = NULL;
    temp->right_child = NULL;
    return temp;
}

// Function to search for a value in the BST
struct node* search(struct node *root, int x) {
    if (root == NULL || root->data == x) {
        return root;
    } else if (x > root->data) {
        return search(root->right_child, x);
    } else {
        return search(root->left_child, x);
    }
}

// Function to insert a value into the BST
struct node* insert(struct node *root, int x) {
    if (root == NULL) {
        return new_node(x);
    } else if (x > root->data) {
        root->right_child = insert(root->right_child, x);
    } else {
        root->left_child = insert(root->left_child, x);
    }
    return root;
}

// Function to find the minimum value node in a BST
struct node* find_minimum(struct node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left_child != NULL) {
        return find_minimum(root->left_child);
    }
    return root;
}

// Function to delete a node from the BST
struct node* delete(struct node *root, int x) {
    if (root == NULL) {
        return NULL;
    }
    
    if (x > root->data) {
        root->right_child = delete(root->right_child, x);
    } else if (x < root->data) {
        root->left_child = delete(root->left_child, x);
    } else {
        // Node with the data x found
        if (root->left_child == NULL && root->right_child == NULL) {
            // Case 1: Node is a leaf node
            free(root);
            return NULL;
        } else if (root->left_child == NULL || root->right_child == NULL) {
            // Case 2: Node has only one child
            struct node *temp = (root->left_child != NULL) ? root->left_child : root->right_child;
            free(root);
            return temp;
        } else {
            // Case 3: Node has two children
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete(root->right_child, temp->data);
        }
    }
    return root;
}

// Function to perform inorder traversal of the BST
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left_child);
        printf(" %d ", root->data);
        inorder(root->right_child);
    }
}

// Driver function to test the BST operations
int main() {
    struct node *root = new_node(20); // Initialize the root of the BST

    // Inserting nodes into the BST
    insert(root, 5);
    insert(root, 1);
    insert(root, 15);
    insert(root, 9);
    insert(root, 7);
    insert(root, 12);
    insert(root, 30);
    insert(root, 25);
    insert(root, 40);
    insert(root, 45);
    insert(root, 42);

    // Perform inorder traversal
    printf("Inorder traversal before deletion:");
    inorder(root);
    printf("\n");

    // Delete some nodes from the BST
    root = delete(root, 1);
    root = delete(root, 40);
    root = delete(root, 45);
    root = delete(root, 9);

    // Perform inorder traversal after deletion
    printf("Inorder traversal after deletion:");
    inorder(root);
    printf("\n");

    return 0;
}