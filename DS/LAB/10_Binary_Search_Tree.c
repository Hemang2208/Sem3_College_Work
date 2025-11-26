#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary tree
Node* insert(struct Node* root, int data) {
    // If tree is empty, create root node
    if (root == NULL) {
        return createNode(data);
    }
    
    // Insert in left subtree if data is less than root
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // Insert in right subtree if data is greater than root
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

// Function to find the minimum value node (used in deletion)
Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the binary tree
Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    
    // Find the node to delete
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        // Node found - handle three cases
        
        // Case 1: Node has no children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        
        // Case 2: Node has one child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Case 3: Node has two children
        else {
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
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
    Node* root = NULL;
    
    // Insert nodes
    printf("Inserting nodes: 50, 30, 70, 20,\n");
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    
    // Display traversals
    printf("\nPreorder Traversal: ");
    preorder(root);
    
    printf("\nInorder Traversal: ");
    inorder(root);
    
    printf("\nPostorder Traversal: ");
    postorder(root);
    
    // Delete a node
    printf("\n\nDeleting node 30...\n");
    root = deleteNode(root, 30);
    
    printf("Inorder Traversal after deletion: ");
    inorder(root);
    
    printf("\n");
    return 0;
}