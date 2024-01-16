#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;


Node *head = NULL;

// add new node to the head
void createNode(int v){
    // allocate node memory
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = v;
    // link newNode to head
    newNode->next = head;
    // set newNode as head
    head = newNode;
}

//! remember: current is just a pointer, not a value
void traverseList(){
    Node *current= head;
    // while current node is not null, print out the current value
    while (current != NULL){
        printf("%d ", current->data); 
        current = current->next;
    }
    printf("\n");
}

void insertAtBeginning(int v){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = v;    
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int v){
    Node *newNode = (Node*) malloc(sizeof(Node));
    Node *current = head;
    newNode->next = NULL; // why this need to be NULL 
    newNode->data = v;

    if (head == NULL){
        head = newNode;
        return;
    }

    while (current->next != NULL){
        current = current->next;
    }
    current->next = newNode;    
}

void deleteNode(int v){
    Node *current = head;
    Node *prev = NULL; // every declare node without value must be NULL
    // delete head
    while (current != NULL && current->data == v){
        head = current->next;
        free(current);
        return;
    }

    // Delete Node by abandening them. Connect 2 Nodes leaving the in between Node 
    while(current != NULL && current->data != v){
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);
    // delete a value
}

void freeLinkedList(){
    printf("Clean Linked List\n");
    Node *current = head;
    Node *nextNode;
    // if the next Node isn't NULL. Delete the current node then move on to the next Node & repeat.
    while (current != NULL){
        nextNode = current->next;
        head = NULL;
        free(current);
        current = nextNode; 
    }
}

int main(){
    createNode(2);
    createNode(3);
    insertAtBeginning(100);
    insertAtEnd(23);
    insertAtEnd(66);
    deleteNode(2);
    insertAtEnd(666);
    

    freeLinkedList();
    traverseList();


    return 0;
}