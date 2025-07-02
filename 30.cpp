#include <stdio.h>

void sort(int a[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (a[i] > a[j]) {
                int t = a[i]; a[i] = a[j]; a[j] = t;
            }
}

int linear(int a[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (a[i] == key) return i;
    return -1;
}

int binary(int a[], int n, int key) {
    int l = 0, h = n-1;
    while (l <= h) {
        int m = (l + h)/2;
        if (a[m] == key) return m;
        else if (key < a[m]) h = m - 1;
        else l = m + 1;
    }
    return -1;
}

int main() {
    int a[100], n, key;
    printf("Size: "); scanf("%d", &n);
    printf("Elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Search: "); scanf("%d", &key);

    int l = linear(a, n, key);
    printf("Linear: %s at %d\n", l != -1 ? "Found" : "Not found", l);

    sort(a, n);
    int b = binary(a, n, key);
    printf("Binary: %s at %d\n", b != -1 ? "Found" : "Not found", b);

    return 0;
}

