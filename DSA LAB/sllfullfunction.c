#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create linked list
void createList(int n) {
    int value;
    struct Node *newNode, *temp;

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

// Insert at first
void insertAtFirst(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert at position
void insertAtPosition(int value, int pos) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete first element
void deleteFirst() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete last element
void deleteLast() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// Delete specific element
void deleteSpecific(int value) {
    struct Node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Display list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int choice, n, value, pos;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create Linked List");
        printf("2. Insert at First");
        printf("3. Insert at End");
        printf("4. Insert at Position");
        printf("5. Delete First");
        printf("6. Delete Last");
        printf("7. Delete Specific Value");
        printf("8. Display List");
        printf("9. Exit");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtFirst(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(value, pos);
                break;

            case 5:
                deleteFirst();
                break;

            case 6:
                deleteLast();
                break;

            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteSpecific(value);
                break;

            case 8:
                display();
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
