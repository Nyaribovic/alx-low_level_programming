#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - Concatenates two strings using at
 *                  most an inputted number of bytes.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of bytes of s2 to concatenate to s1.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - a pointer to the concatenated space in memory.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    unsigned int len1 = 0, len2 = 0;
    char *result, *p;

    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";

    while (s1[len1] != '\0')
        len1++;
    while (s2[len2] != '\0')
        len2++;

    if (n >= len2)
        n = len2;

    result = malloc(sizeof(char) * (len1 + n + 1));
    if (result == NULL)
        exit(EXIT_FAILURE);

    p = result;
    while (*s1 != '\0') {
        *p = *s1;
        p++;
        s1++;
    }

    while (n > 0) {
        *p = *s2;
        p++;
        s2++;
        n--;
    }

    *p = '\0';

    return (result);
}
