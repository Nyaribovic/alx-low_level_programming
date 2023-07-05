#include "main.h"
#include <stdio.h>

/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: The string to be checked
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len, i;

	/* Calculate the length of the string */
	for (len = 0; s[len] != '\0'; len++)
		;

	/* Empty string is a palindrome */
	if (len == 0)
		return 1;

	/* Check if the string is a palindrome */
	for (i = 0; i < len / 2; i++)
	{
		if (s[i] != s[len - 1 - i])
			return 0; /* Not a palindrome */
	}

	return 1; /* Palindrome */
}
