#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insert(struct node *head, int value) {
    struct node *newNode = malloc(sizeof *newNode);
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = head;
    return newNode;
}

void printList(struct node *head) {
    struct node *temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;

    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);

    printList(head);
    return 0;
}
