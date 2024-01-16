#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho de cap phat!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the head of the linked list
void addToHead(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory of the linked list
void freeList(Node** head) {
    Node* current = *head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    Node* myList = NULL;

    // Add some nodes to the linked list
    addToHead(&myList, 3);
    addToHead(&myList, 7);
    addToHead(&myList, 10);

    // Print the linked list
    printf("Danh sach lien ket ban dau: ");
    printList(myList);

    // Free the memory of the linked list
    freeList(&myList);

    // Print the list after freeing the memory
    printf("Danh sach sau khi giai phong bo nho: ");
    printList(myList);

    return 0;
}
