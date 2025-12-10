#include<stdio.h>

int main() {
    int top = -1, n, choice, value;

    printf("Enter stack size: ");
    scanf("%d", &n);
    int arr[n];

    do {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (top == n - 1) {
                printf("Stack Overflow!\n");
            } else {
                printf("Enter value: ");
                scanf("%d", &value);
                arr[++top] = value;
                printf("%d pushed.\n", value);
            }
        } else if (choice == 2) {
            if (top == -1) {
                printf("Stack Underflow\n");
            } else {
                printf("%d popped.\n", arr[top--]);
            }
        } else if (choice == 3) {
            if (top == -1) {
                printf("Stack is empty\n");
            } else {
                printf("Stack elements: ");
                for (int i = 0; i <= top; i++)
                    printf("%d ", arr[i]);
                printf("\n");
            }
        } else if (choice != 4) {
            printf("Invalid choice!\n");
        }
    } while (choice != 4);

    printf("Goodbye!\n");
    return 0;
}
