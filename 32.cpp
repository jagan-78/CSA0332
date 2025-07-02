#include <stdio.h>

int main() {
    int arr[100], n, sum = 0, total;

    printf("Enter number of elements (n): ");
    scanf("%d", &n);  // n elements, but 1 is missing from 1 to n+1

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    total = (n + 1) * (n + 2) / 2;  // Sum of 1 to n+1
    printf("Missing element: %d\n", total - sum);

    return 0;
}

