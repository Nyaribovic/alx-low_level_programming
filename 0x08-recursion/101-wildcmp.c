#include "main.h"
#include <stdio.h>

/**
 * wildcmp - Compares two strings, considering wildcard characters.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared - may contain wildcards.
 *
 * Return: If the strings can be considered identical - 1.
 *         Otherwise - 0.
 */
int wildcmp(char *s1, char *s2) {
    // If both strings are empty, they are considered identical
    if (*s1 == '\0' && *s2 == '\0') {
        return 1;
    }

    // If s2 is '*', it can replace any string (including an empty string),
    // so we recursively check the remaining characters of s1 and s2
    if (*s2 == '*') {
        // Case 1: '*' matches an empty string, so we check if s1 and s2 without '*'
        // are identical (recursively)
        if (wildcmp(s1, s2 + 1) == 1) {
            return 1;
        }

        // Case 2: '*' matches one or more characters in s1, so we check if
        // the remaining characters of s1 and s2 are identical (recursively)
        if (*s1 != '\0' && wildcmp(s1 + 1, s2) == 1) {
            return 1;
        }
    }

    // If the characters at the current positions of s1 and s2 are equal,
    // or if s1 and s2 are both not empty and the character at s2 is '?',
    // we recursively check the next characters
    if (*s1 == *s2 || (*s1 != '\0' && *s2 == '?')) {
        return wildcmp(s1 + 1, s2 + 1);
    }

    // If none of the above conditions are met, the strings cannot be considered identical
    return 0;
}


