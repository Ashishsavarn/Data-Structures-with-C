#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void initializeStack(Stack *s);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
void display(Stack *s);
bool isPalindrome(int arr[], int n);
void checkOverflowUnderflow(Stack *s);

int main() {
    printf("Ashish's(1AY23CS040) Program!\n\n");
    Stack stack;
    initializeStack(&stack);
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Push an Element onto Stack\n");
        printf("2. Pop an Element from Stack\n");
        printf("3. Check Palindrome\n");
        printf("4. Demonstrate Overflow and Underflow\n");
        printf("5. Display Stack Status\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 2:
                value=pop(&stack);
                if (value!=-1) {
                    printf("Popped value: %d\n", value);
                }
                break;

            case 3:
                printf("Enter the number of elements for palindrome check: ");
                int n;
                scanf("%d", &n);
                if (n>MAX) {
                    printf("Cannot check palindrome, exceeds maximum stack size.\n");
                } else {
                    int tempArr[MAX];
                    printf("Enter %d elements:\n", n);
                    for (int i=0; i<n; i++) {
                        scanf("%d", &tempArr[i]);
                    }
                    if (isPalindrome(tempArr, n)) {
                        printf("The array is a palindrome.\n");
                    } else {
                        printf("The array is not a palindrome.\n");
                    }
                }
                break;

            case 4:
                checkOverflowUnderflow(&stack);
                break;

            case 5:
                display(&stack);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}
void initializeStack(Stack *s) {
    s->top=-1;
}
bool isFull(Stack *s) {
    return s->top == MAX - 1;
}
bool isEmpty(Stack *s) {
    return s->top==-1;
}
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        s->arr[++s->top]=value;
        printf("Pushed %d onto the stack.\n", value);
    }
}
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1;
    } else {
        return s->arr[s->top--];
    }
}
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i=0; i<=s->top; i++) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}
bool isPalindrome(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - i - 1]) {
            return false;
        }
    }
    return true;
}
void checkOverflowUnderflow(Stack *s) {
    printf("Demonstrating Stack Overflow:\n");
    for (int i=0; i<MAX+1; i++) {
        push(s, i);
    }

   initializeStack(s);
   

    printf("Demonstrating Stack Underflow:\n");
    for (int i=0; i<MAX + 1; i++) {
        pop(s); 
    }
}
