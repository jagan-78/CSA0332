#include <stdio.h>

int main() {
    int arr[100], n, i, key, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter number to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("%d found at position %d (index %d)\n", key, i+1, i);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("%d not found in the list\n", key);

    return 0;
}

