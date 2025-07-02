#include <stdio.h>
#define SIZE 100

int stack[SIZE], top = -1;

void push(int x) {
    if (top == SIZE - 1) printf("Overflow\n");
    else stack[++top] = x;
}

void pop() {
    if (top == -1) printf("Underflow\n");
    else printf("Popped: %d\n", stack[top--]);
}

void display() {
    if (top == -1) printf("Empty\n");
    else {
        for (int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int ch, x;
    while (1) {
        printf("1.Push 2.Pop 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Value: ");
            scanf("%d", &x);
            push(x);
        } else if (ch == 2) pop();
        else if (ch == 3) display();
        else if (ch == 4) break;
        else printf("Invalid\n");
    }
    return 0;
}

