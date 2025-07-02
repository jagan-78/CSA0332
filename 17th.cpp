#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Merge two lists
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;

    return head1;
}

// Display list
void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Input for first list
    insertEnd(&list1, 1);
    insertEnd(&list1, 2);
    insertEnd(&list1, 3);

    // Input for second list
    insertEnd(&list2, 4);
    insertEnd(&list2, 5);
    insertEnd(&list2, 6);

    printf("List 1: ");
    displayList(list1);
    printf("List 2: ");
    displayList(list2);

    // Merge
    struct Node* merged = mergeLists(list1, list2);
    printf("Merged List: ");
    displayList(merged);

    return 0;
}

