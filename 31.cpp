#include <stdio.h>

int main() {
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (n >= 5)
        printf("5th element: %d\n", arr[4]); // Index starts at 0
    else
        printf("Less than 5 elements. No 5th element.\n");

    return 0;
}

