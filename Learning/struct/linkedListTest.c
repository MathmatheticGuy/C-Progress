#include <stdio.h>   // Standard Input/Output library
#include <stdlib.h>  // Standard Library for general functions


typedef struct Node{
    int data; // Node value
    struct Node* next; // pointer to the next pointer
} Node;

// Create head pointer
Node *head = NULL;

// create Node & link Nodes
void CreateNode(int v){
    // See Node as a structure template
    // from the template we create a Node with that attributes
    Node* newNode = (Node*) malloc(sizeof(Node));

    // assigned value to Node data
    newNode->data = v;
    // link node to the head (from the right)
    newNode->next = head;
    // adjust head node to NewNode (bc head is the rightest Node)
    head = newNode;
} 


void traverseList(){
    Node* current = head;
    if (head != NULL){
        printf("(head) ");
    }
    while (current != NULL){
        printf("%d ", current->data); 
        current = current->next;
        if (current == NULL && head != NULL) {
            printf("(tail)");
        }
    }
}

void insertAtHead(int v) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(int v){
    // newNode ist a pointer pointed to a memory block that hold Node data
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = NULL;

    if (head == NULL){
        head = newNode;
        return;
    }
    else{
        // point the poitner to head to traverse till the end of list
        Node* current = head;
        while (current->next != NULL){
            // traverse to the end of the list
            current = current->next;
        }
        // Replace the NULL value at the tail as newNode
        current->next = newNode;
    }
}

void deleteNode(int v){
    Node* temp = head;
    Node* prev = NULL;

    // check if delete value is head Node
    while (temp->next != NULL && temp->data == v){
        // quick delete operation for head Node
        head = temp->next;
        free(temp);
        return;
    }
    // traverse the list if not found the Node value
    while (temp->next != NULL && temp->data != v){
        prev = temp;
        temp = temp->next; //? *temp always 1 Node ahead of *prev
    } // the loop auto break if the value if found

    // connect 2 Node pointer leaving the interwince Node be NULL
    prev->next = temp->next;
    // prev and temp are now pointed to the same Nodes
    // free 1 out of 2 to avoid duplicate pointer
    free(temp);  
}

void freeLinkedList(){
    Node* temp = head;
    Node* nextNode;
    // goals: make *temp pointed to the next value and deleted it. Then redirect temp to the next Node and repeat.
    while (temp->next != NULL){ 
        head = NULL; // deleting head manually bc *temp pointed to the next node. So head won't be delete in the loop
        nextNode = temp->next; // get the nextNode before the current memory was free  
        free(temp); // free the current memory block temp pointed to
        temp = nextNode;
        
    } // deleting all value after head Node
    
}

int main(){
    //! remember: traverse to the left. Head (left) to Tail (right)
    for (int i = 5; i > 0; i--){
        CreateNode(i);
        // printf("%d ", i);
    }
    printf("\n");
    insertAtHead(111);
    insertAtTail(222);
    deleteNode(111);

    freeLinkedList();
    traverseList();
    

    return 0;
}