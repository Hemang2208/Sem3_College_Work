#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert left child
struct Node* insertLeft(struct Node* parent, int data) {
    if (parent == NULL) {
        printf("Parent node is NULL!\n");
        return NULL;
    }
    
    if (parent->left != NULL) {
        printf("Left child already exists!\n");
        return parent->left;
    }
    
    parent->left = createNode(data);
    return parent->left;
}

// Function to insert right child
struct Node* insertRight(struct Node* parent, int data) {
    if (parent == NULL) {
        printf("Parent node is NULL!\n");
        return NULL;
    }
    
    if (parent->right != NULL) {
        printf("Right child already exists!\n");
        return parent->right;
    }
    
    parent->right = createNode(data);
    return parent->right;
}

// Function to search for a node with given data
struct Node* search(struct Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    
    if (root->data == data) {
        return root;
    }
    
    // Search in left subtree
    struct Node* leftResult = search(root->left, data);
    if (leftResult != NULL) {
        return leftResult;
    }
    
    // Search in right subtree
    return search(root->right, data);
}

// Function to delete a node (replaces it with NULL)
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    
    // If root is the node to delete
    if (root->data == data) {
        free(root);
        return NULL;
    }
    
    // Recursively delete from left or right subtree
    root->left = deleteNode(root->left, data);
    root->right = deleteNode(root->right, data);
    
    return root;
}

// Preorder Traversal (Root -> Left -> Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder Traversal (Left -> Root -> Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Postorder Traversal (Left -> Right -> Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main function to demonstrate the binary tree operations
int main() {
    // Create root node
    struct Node* root = createNode(1);
    
    // Build the tree manually
    printf("Building binary tree...\n");
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);
    insertRight(root->left, 5);
    insertLeft(root->right, 6);
    insertRight(root->right, 7);
    
    /*
     Tree structure:
           1
          / \
         2   3
        / \ / \
       4  5 6  7
    */
    
    // Display traversals
    printf("\nPreorder Traversal: ");
    preorder(root);
    
    printf("\nInorder Traversal: ");
    inorder(root);
    
    printf("\nPostorder Traversal: ");
    postorder(root);
    
    // Delete a node
    printf("\n\nDeleting node 5...\n");
    root = deleteNode(root, 5);
    
    printf("Inorder Traversal after deletion: ");
    inorder(root);
    
    printf("\n");
    return 0;
}