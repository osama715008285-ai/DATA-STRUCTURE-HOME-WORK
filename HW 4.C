#include <stdio.h>
#include <stdlib.h>

// Structure for Doubly Linked List node
struct Box {
    int val;
    struct Box* next;
    struct Box* prev;
};

// Function to add item at the end
void append(struct Box** head, struct Box** tail, int data) {
    struct Box* newBox = (struct Box*)malloc(sizeof(struct Box));
    newBox->val = data;
    newBox->next = NULL;
    newBox->prev = NULL;

    if (*head == NULL) {
        *head = newBox;
        *tail = newBox;
        return;
    }

    (*tail)->next = newBox;
    newBox->prev = *tail;
    *tail = newBox;
}

// Function to delete the list (Recursion style)
void clearAll(struct Box* head) {
    if (head == NULL) return;
    clearAll(head->next);
    free(head);
}

// Function to add at a specific place
void addAt(struct Box** head, struct Box** tail, int data, int pos) {
    struct Box* newBox = (struct Box*)malloc(sizeof(struct Box));
    newBox->val = data;
    newBox->next = NULL;
    newBox->prev = NULL;

    if (pos == 0) {
        newBox->next = *head;
        if (*head != NULL) (*head)->prev = newBox;
        *head = newBox;
        if (*tail == NULL) *tail = newBox;
        return;
    }

    struct Box* curr = *head;
    for (int i = 0; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Out of range\n");
        free(newBox);
        return;
    }

    newBox->next = curr->next;
    newBox->prev = curr;

    if (curr->next != NULL)
        curr->next->prev = newBox;
    else
        *tail = newBox;

    curr->next = newBox;
}

int main() {
    struct Box* h = NULL;
    struct Box* t = NULL;

    append(&h, &t, 10);
    append(&h, &t, 20);
    addAt(&h, &t, 15, 1);

    printf("Forward List: ");
    struct Box* temp = h;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");

    clearAll(h);
    h = NULL; t = NULL;

    return 0;
}

/*
   Difference between Circular and Normal Linked List
  1. Normal ends with NULL, Circular points back to the first node.
  2. Normal is easy to loop, Circular needs a stop condition to avoid infinite loop.
  3. Circular is better for things like game turns or buffers.
  4. Sorting Normal is easier because it has a clear end.
*/
