#include <stdio.h>

int main() {
    int arr[100], n, i, key, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to find: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            found = 1;
            printf("Element %d found at position %d (index %d).\n", key, i + 1, i);
            break;
        }
    }

    if(!found) {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}

