#include <stdio.h>
#include <ctype.h>

int isValidString(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalnum(str[i])) {
            return 0; // Invalid character found
        }
    }
    return 1; // All characters are valid
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isValidString(str)) {
        printf("Valid string (only letters and digits).\n");
    } else {
        printf("Invalid string (contains special characters).\n");
    }

    return 0;
}

