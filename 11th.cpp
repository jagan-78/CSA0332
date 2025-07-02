#include <stdio.h>
#define SIZE 100

int stack[SIZE], top = -1;

void push(int val) {
    if(top < SIZE - 1) stack[++top] = val;
    else printf("Overflow\n");
}

void pop() {
    if(top >= 0) printf("Popped: %d\n", stack[top--]);
    else printf("Underflow\n");
}

void peek() {
    if(top >= 0) printf("Top: %d\n", stack[top]);
    else printf("Empty\n");
}

int main() {
    push(10); push(20); push(30);
    peek();     // Top: 30
    pop();      // Popped: 30
    peek();     // Top: 20
    return 0;
}

