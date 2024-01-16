#include <stdio.h>   // Standard Input/Output library
#include <stdlib.h>  // Standard Library for general functions

//! 1. Define node Structure
struct Node {
    int data;          // Data to be stored in the node
    struct Node* next; // Pointer to the next node
};

//! 2. Create Head Pointer
struct Node* head = NULL;

//! 3. Create Nodes and Link Them
/**
 * Creates a new node with the given value and links it to the existing list.
 * @param v The value to be stored in the new node.
 */
void createAndLinkNodes(int v) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Assign data to the node
    newNode->data = v;  // Example data

    // Link the new node to the existing list
    newNode->next = head;

    // Update the head pointer to point to the new node
    head = newNode;
}

//! 4. Traverse (Duyệt) the List :
/**
 * Traverses the linked list and prints the data of each node.
 */
void traverseList() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

//! 5. Insert Nodes
// Insert at the beginning
/**
 * Inserts a new node with the given data at the beginning of the linked list.
 * @param data The data to be stored in the new node.
 */
void insertAtBeginning(int data) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data; // Assign the given data to the new node
    newNode->next = head;
    head = newNode;
}

// Insert at the end
/**
 * Inserts a new node with the given data at the end of the linked list.
 * @param data The data to be stored in the new node.
 */
void insertAtEnd(int data) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data; // Assign the given data to the new node
    newNode->next = NULL;

    // Assign head to the node if the list is empty
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Traverse to the end of the list
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Link the new node to the end of the list
    current->next = newNode;
}

//! 6. Delete Nodes
// Delete a node with a specific value
/** 
 * Deletes the first occurrence of a node with the given data from the linked list.
 * @param data The data of the node to be deleted.
 */
void deleteNode(int data) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    // not deleting prev because it use to connect 2 Node
    free(temp);
}

// Free the memory of the linked list
/**
 * Frees the memory allocated for the linked list.
 */
void freeLinkedList() {
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next; // Lưu trữ con trỏ tới node tiếp theo
        free(current);        // Giải phóng bộ nhớ của node hiện tại
        current = next;       // Di chuyển tới node tiếp theo
    }

    head = NULL; // Reset the head pointer
}

int main() {
    createAndLinkNodes(5); // Create and link nodes
    createAndLinkNodes(10); // Create and link nodes
    createAndLinkNodes(11); // Create and link nodes
    createAndLinkNodes(7); // Create and link nodes
    
    freeLinkedList(); // Free the memory of the linked list

    createAndLinkNodes(2); // Create and link nodes
    insertAtEnd(211); // Insert at the end
    insertAtBeginning(42); // Insert at the end
    

    traverseList(); // Traverse the list and print the data

    freeLinkedList(); // Free the memory of the linked list
    printf("\n Linked list after freeing up memory");
    traverseList(); // Traverse the list and print the data

    return 0;
}
