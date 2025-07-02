#include <stdio.h>

int main() {
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Even numbers:\n");
    for(i = 0; i < n; i++) {
        if(arr[i] % 2 == 0)
            printf("%d ", arr[i]);
    }

    printf("\nOdd numbers:\n");
    for(i = 0; i < n; i++) {
        if(arr[i] % 2 != 0)
            printf("%d ", arr[i]);
    }

    return 0;
}

