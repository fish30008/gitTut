#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* getNewNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert_value(Node** root, int data) {
    if (*root == NULL) {
        *root = getNewNode(data);
        return; // Removed returning root pointer
    }
    if (data <= (*root)->data) {
        insert_value(&((*root)->left), data);
    } else {
        insert_value(&((*root)->right), data);
    }
}

bool search(Node* root, int data) {
    if (root == NULL) {
        return false;
    } else if (root->data == data) {
        return true;
    } else if (data < root->data) { // Changed <= to <
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

int main() {
    Node* root = NULL;
    insert_value(&root, 15);
    insert_value(&root, 155);
    insert_value(&root, 1555);
    return 0;
}
