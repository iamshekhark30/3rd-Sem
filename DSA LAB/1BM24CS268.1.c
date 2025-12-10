#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int main() {
    int n, i;
    int arr[MAX_SIZE];
    Stack stack;

    init(&stack);

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        push(&stack, arr[i]);
    }
    printf("Reversed list:\n");
    for (i = 0; i < n; i++) {
        arr[i] = pop(&stack);
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
