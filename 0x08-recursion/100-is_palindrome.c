#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * find_strlen - Returns the length of a string.
 * @s: The string to be measured.
 *
 * Return: The length of the string.
 */
int is_palindrome(char *s) {
    int len = strlen(s);
    int start = 0;
    int end = len - 1;

    while (start < end) {
        if (s[start] != s[end]) {
            return 0;  // Not a palindrome
        }

        start++;
        end--;
    }

    return 1;  // Palindrome
}

int main() {
    char str[] = s;
    int result = is_palindrome(str);

    if (result == 1) {
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }

    return 0;
}
