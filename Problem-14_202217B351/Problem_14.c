#include <stdio.h>

#define MAX_NODE 15

// Define the binary tree using an array representation
char tree[] = {'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0', 
                'V', '\0', 'J', 'L'};

// Function to get the index of the right child
int get_right_child(int index) {
    if (tree[index] != '\0' && ((2 * index) + 1) <= MAX_NODE) {
        return (2 * index) + 1;
    }
    return -1;
}

// Function to get the index of the left child
int get_left_child(int index) {
    if (tree[index] != '\0' && (2 * index) <= MAX_NODE) {
        return 2 * index;
    }
    return -1;
}

// Pre-order traversal: Visit root, then left subtree, then right subtree
void preorder(int index) {
    if (index > 0 && tree[index] != '\0') {
        printf(" %c ", tree[index]); // Visit root
        preorder(get_left_child(index)); // Traverse left subtree
        preorder(get_right_child(index)); // Traverse right subtree
    }
}

// Post-order traversal: Traverse left subtree, then right subtree, then visit root
void postorder(int index) {
    if (index > 0 && tree[index] != '\0') {
        postorder(get_left_child(index)); // Traverse left subtree
        postorder(get_right_child(index)); // Traverse right subtree
        printf(" %c ", tree[index]); // Visit root
    }
}

// In-order traversal: Traverse left subtree, visit root, then traverse right subtree
void inorder(int index) {
    if (index > 0 && tree[index] != '\0') {
        inorder(get_left_child(index)); // Traverse left subtree
        printf(" %c ", tree[index]); // Visit root
        inorder(get_right_child(index)); // Traverse right subtree
    }
}

// Main function to test the tree traversals
int main() {
    printf("Preorder:\n");
    preorder(1); // Start traversal from the root node (index 1)
    printf("\nPostorder:\n");
    postorder(1); // Start traversal from the root node (index 1)
    printf("\nInorder:\n");
    inorder(1); // Start traversal from the root node (index 1)
    printf("\n");
    return 0;
}
