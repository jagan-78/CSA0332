#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data, height;
    struct Node *left, *right;
};

int height(struct Node* n) {
    return n ? n->height : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct Node* create(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(struct Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

struct Node* insert(struct Node* node, int key) {
    if (!node) return create(key);
    if (key < node->data) node->left = insert(node->left, key);
    else if (key > node->data) node->right = insert(node->right, key);
    else return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data) return rightRotate(node);
    if (balance < -1 && key > node->right->data) return leftRotate(node);
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left); return rightRotate(node);
    }
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right); return leftRotate(node);
    }

    return node;
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, x;
    printf("Enter count: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    while (n--) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    printf("In-order: ");
    inorder(root);
    return 0;
}

