#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList(struct Node* head) {
    struct Node* i, *j;
    int temp;
    if (head == NULL) return;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node* concatenate(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    struct Node* temp = list1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = list2;
    return list1;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int choice, data;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert into List1   ");
        printf("2. Insert into List2   ");
        printf("3. Display List1  ");
        printf("4. Display List2   ");
        printf("5. Sort List1   ");
        printf("6. Reverse List1  ");
        printf("7. Concatenate List1 and List2  ");
        printf("8. Exit  ");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert into List1: ");
                scanf("%d", &data);
                insertEnd(&list1, data);
                break;
            case 2:
                printf("Enter data to insert into List2: ");
                scanf("%d", &data);
                insertEnd(&list2, data);
                break;
            case 3:
                printf("List1: ");
                display(list1);
                break;
            case 4:
                printf("List2: ");
                display(list2);
                break;
            case 5:
                sortList(list1);
                printf("List1 sorted.\n");
                break;
            case 6:
                list1 = reverseList(list1);
                printf("List1 reversed.\n");
                break;
            case 7:
                list1 = concatenate(list1, list2);
                printf("Concatenated List: ");
                display(list1);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
