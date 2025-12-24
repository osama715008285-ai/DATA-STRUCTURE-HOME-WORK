#include <stdio.h>
#include <stdlib.h>

// ============================
// Node Structure
// Time Complexity: O(1)
// ============================
typedef struct Node {
    int data;
    struct Node* next;
} Node;


// ============================
// Create a New Node
// Time Complexity: O(1)
// ============================
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


// ============================
// Insert at the Beginning (Head)
// Time Complexity: O(1)
// ============================
void insertAtHead(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}


// ============================
// Insert at the End
// Time Complexity: O(n)
// ============================
void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}


// ============================
// Insert at a Specific Position
// Time Complexity: O(n)
// ============================
void insertAtPosition(Node** head, int value, int position) {
    if (position == 0) {
        insertAtHead(head, value);
        return;
    }

    Node* newNode = createNode(value);
    Node* temp = *head;

    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


// ============================
// Delete from the Beginning (Head)
// Time Complexity: O(1)
// ============================
void deleteHead(Node** head) {
    if (*head == NULL) return;

    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}


// ============================
// Delete from the End
// Time Complexity: O(n)
// ============================
void deleteEnd(Node** head) {
    if (*head == NULL) return;

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}


// ============================
// Delete from a Specific Position
// Time Complexity: O(n)
// ============================
void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) return;

    if (position == 0) {
        deleteHead(head);
        return;
    }

    Node* temp = *head;

    for (int i = 0; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}


// ============================
// Traversal (Print List)
// Time Complexity: O(n)
// ============================
void printList(Node* head) {
    Node* temp = head;

    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


// ============================
// Main Function (Testing)
// ============================
int main() {
    Node* head = NULL;

    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtEnd(&head, 5);
    insertAtPosition(&head, 15, 1);

    printList(head);

    deleteHead(&head);
    printList(head);

    deleteEnd(&head);
    printList(head);

    deleteAtPosition(&head, 1);
    printList(head);

    return 0;
}
