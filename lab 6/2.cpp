#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node {
    char data;
    struct Node* next;
};

// Top pointer for the stack
struct Node* top = NULL;

// Function prototypes
void push(char val);
void pop();
void peek();
void menu();

int main() {
    int choice;
    char ch;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to push: ");
                scanf(" %c", &ch); // space to skip newline
                push(ch);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

// Menu display
void menu() {
    printf("\nMenu\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Exit\n");
}

// Push operation
void push(char val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = val;
    newnode->next = top;
    top = newnode;
    printf("Pushed: %c\n", val);
}

// Pop operation
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    struct Node* temp = top;
    printf("Popped: %c\n", temp->data);
    top = top->next;
    free(temp);
}

// Peek operation
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %c\n", top->data);
    }
}
