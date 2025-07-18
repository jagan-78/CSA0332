#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        // Check for overflow
        if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && digit > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && digit < -8)) return 0;

        rev = rev * 10 + digit;
    }
    return rev;
}

int main() {
    int num;
    printf("Enter a 32-bit signed integer: ");
    scanf("%d", &num);

    int result = reverse(num);
    printf("Reversed number: %d\n", result);
    return 0;
}

