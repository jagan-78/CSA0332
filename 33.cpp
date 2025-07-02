#include <stdio.h>

int main() {
    int a[100], b[100], c[200];
    int n1, n2, i, k = 0;

    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter elements:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
        c[k++] = a[i];
    }

    printf("Enter size of second array: ");
    scanf("%d", &n2);
    printf("Enter elements:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
        c[k++] = b[i];
    }

    printf("Concatenated array:\n");
    for (i = 0; i < n1 + n2; i++)
        printf("%d ", c[i]);

    return 0;
}

