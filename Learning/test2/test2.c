#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int inputNum(){
    int num;
    do{
        printf("Enter a number: ");
        scanf("%d", &num);
    }
    while(num < 1 || num > 20);
    printf("The hexadecimal representation of %d is %x\n", num, num);

    return num;
}

// Extracting the 4 least significant bits of n
int extractBits(int n) {
    int bitmask = 0xF; // bitmask with 4 least significant bits set to 1
    int result = n & bitmask; // perform bitwise AND operation
    return result;
}

// Define the Book structure
struct Book {
    char bookID[50];
    char bookTitle[100];
    int pageCount;
    int year;
    struct Book* next;
};

// Function to input a list of books from the keyboard
struct Book* inputBookList(int n) {
    struct Book* head = NULL;
    struct Book* current = NULL;

    for (int i = 0; i < n; ++i) {
        struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));

        // Input book details from the keyboard
        printf("Enter details for Book %d:\n", i + 1);
        printf("Book ID: ");
        scanf("%s", newBook->bookID);
        getchar(); // Clear the input buffer
        
        printf("Book Title: ");
        fgets(newBook->bookTitle, sizeof(newBook->bookTitle), stdin);
        char *newline = strchr(newBook->bookTitle, '\n'); // Check for newline character
        if (newline) *newline = '\0'; // If found, replace it with null character

5
        printf("Page Count: ");
        scanf("%d", &newBook->pageCount);

        // Check pageCount to end input
        if (newBook->pageCount <= 0) {
            free(newBook);  // Free memory if pageCount is invalid
            break;
        }

        printf("Year: ");
        scanf("%d", &newBook->year);

        newBook->next = NULL;

        // If it's the first book, make it the head
        if (head == NULL) {
            head = newBook;
            current = head;
        } else {
            // Otherwise, link it to the previous book
            current->next = newBook;
            current = newBook;
        }
    }

    return head;
}

// Function to write a singly linked list of books to a text file
void writeBookListToFile(struct Book* head, const char* filename) {
    // Open the file in write mode
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    // Traverse the linked list and write each book's information to the file
    struct Book* current = head;
    while (current != NULL) {
        fprintf(file, "Book ID: %s, Title: %s, Page Count: %d, Year: %d\n",
            current->bookID, current->bookTitle, current->pageCount, current->year);
        current = current->next;
    }

    // Close the file
    fclose(file);
}


int main(){
    int num2;
    num2 = inputNum();

    int extractedBits = extractBits(num2);
    printf("The 4 least significant bits of %d are %d\n", num2, extractedBits);
    
    //! Book section
    int bookNum;
    printf("Enter the number of books: ");
    scanf("%d", &bookNum);

    struct Book* head = NULL;
    head = inputBookList(bookNum);

    // Display information of the imported books
    printf("\nBook List:\n");
    struct Book* current = head;
    while (current != NULL) {
        printf("Book ID: %s, Title: %s, Page Count: %d, Year: %d\n",
            current->bookID, current->bookTitle, current->pageCount, current->year);
        current = current->next;
    }

    // Display information of books published in 2020
    printf("\nBooks published in 2020:\n");
    current = head;
    while (current != NULL) {
        if (current->year == 2020) {
            printf("Book ID: %s, Title: %s, Page Count: %d, Year: %d\n",
                current->bookID, current->bookTitle, current->pageCount, current->year);
        }
        current = current->next;
    }

    // Free memory of the book list
    current = head;
    while (current != NULL) {
        struct Book* temp = current;
        current = current->next;
        free(temp);
    }

    // Call writeBookListToFile function to write the list to the file
    writeBookListToFile(head, "namesach_sach.txt");

    // Release the memory allocated for the list and reassign the value to head
    current = head;
    while (current != NULL) {
        struct Book* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    
    return 0;
}