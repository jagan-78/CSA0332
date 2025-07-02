#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* create(int value) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = value;
    n->left = n->right = NULL;
    return n;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (!root) return create(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Search element
int search(struct Node* root, int key) {
    if (!root) return 0;
    if (root->data == key) return 1;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Find min element
int findMin(struct Node* root) {
    while (root->left)
        root = root->left;
    return root->data;
}

// Find max element
int findMax(struct Node* root) {
    while (root->right)
        root = root->right;
    return root->data;
}

int main() {
    struct Node* root = NULL;
    int n, val, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);
    if (search(root, key))
        printf("Element %d found.\n", key);
    else
        printf("Element %d not found.\n", key);

    printf("Minimum element: %d\n", findMin(root));
    printf("Maximum element: %d\n", findMax(root));

    return 0;
}

