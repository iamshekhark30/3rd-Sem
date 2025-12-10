#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* push(struct Node* top, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = top;
    top = newNode;
    return top;
}

struct Node* pop(struct Node* top) {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return NULL;
    }
    printf("Popped: %d\n", top->data);
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

void displayStack(struct Node* top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

struct Node* enqueue(struct Node* rear, int value) {
    struct Node* newNode = createNode(value);
    if (rear == NULL) {
        return newNode;
    }
    struct Node* temp = rear;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return rear;
}

struct Node* dequeue(struct Node* rear) {
    if (rear == NULL) {
        printf("Queue Underflow!\n");
        return NULL;
    }
    printf("Dequeued: %d\n", rear->data);
    struct Node* temp = rear;
    rear = rear->next;
    free(temp);
    return rear;
}

void displayQueue(struct Node* rear) {
    printf("Queue: ");
    while (rear != NULL) {
        printf("%d -> ", rear->data);
        rear = rear->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* stackTop = NULL;
    struct Node* queueFront = NULL;
    int choice, value;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Push (Stack)  ");
        printf("2. Pop (Stack)  ");
        printf("3. Display Stack  ");
        printf("4. Enqueue (Queue)  ");
        printf("5. Dequeue (Queue)  ");
        printf("6. Display Queue  ");
        printf("7. Exit  ");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                stackTop = push(stackTop, value);
                break;
            case 2:
                stackTop = pop(stackTop);
                break;
            case 3:
                displayStack(stackTop);
                break;
            case 4:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                queueFront = enqueue(queueFront, value);
                break;
            case 5:
                queueFront = dequeue(queueFront);
                break;
            case 6:
                displayQueue(queueFront);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
