#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct Book {
    int id;
    char title[50];
    struct Book *next;
};

int queue[SIZE];
int front = -1, rear = -1;

int stack[SIZE];
int top = -1;

struct Book *head = NULL;

void addBook(int id, char title[]) {
    struct Book *newBook = (struct Book *)malloc(sizeof(struct Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    newBook->next = head;
    head = newBook;
}

void viewBooks() {
    struct Book *temp = head;
    while (temp != NULL) {
        printf("Book ID: %d, Title: %s\n", temp->id, temp->title);
        temp = temp->next;
    }
}

void enqueue(int id) {
    if (rear == SIZE - 1) return;
    if (front == -1) front = 0;
    rear++;
    queue[rear] = id;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void push(int id) {
    if (top == SIZE - 1) return;
    stack[++top] = id;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int main() {
    int choice, id;
    char title[50];

    while (1) {
        printf("\n1. Add Book\n2. Request to Borrow\n3. Process Borrowing\n4. Return Book\n5. Show Returned Books\n6. View All Books\n7. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Book ID: ");
            scanf("%d", &id);
           printf("Enter Title: ");
           scanf(" %[^\n]", title);
            addBook(id, title);
        } else if (choice == 2) {
            printf("Enter Book ID to Request: ");
            scanf("%d", &id);
            enqueue(id);
        } else if (choice == 3) {
            id = dequeue();
            if (id == -1) printf("No pending requests.\n");
            else printf("Book ID %d has been borrowed.\n", id);
        } else if (choice == 4) {
            printf("Enter Returned Book ID: ");
            scanf("%d", &id);
            push(id);
        } else if (choice == 5) {
            id = pop();
            if (id == -1) printf("No returned books.\n");
            else printf("Book ID %d was recently returned.\n", id);
        } else if (choice == 6) {
            viewBooks();
        } else if (choice == 7) {
            break;
        }
    }

    return 0;
}

