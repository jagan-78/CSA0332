#include <stdio.h>

int main() {
    int reg[100], n, i, key, found = 0;

    printf("Enter number of register numbers: ");
    scanf("%d", &n);

    printf("Enter the register numbers:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &reg[i]);
    }

    printf("Enter the register number to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        if(reg[i] == key) {
            found = 1;
            break;
        }
    }

    if(found)
        printf("Register number %d found at position %d.\n", key, i+1);
    else
        printf("Register number %d not found.\n", key);

    return 0;
}

