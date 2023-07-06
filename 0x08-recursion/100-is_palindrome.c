#include "main.h"
#include <stdio.h>

/**
 * str_len - Calculates the length of a string
 * @s: The string
 *
 * Return: The length of the string
 */
int str_len(char *s)
{
	if (*s == '\0')
		return (0);

	return 1 + str_len(s + 1);
}

/**
 * is_palindrome_helper - Helper function to check if a string is palindrome
 * @s: The string
 * @start: The start index
 * @end: The end index
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome_helper(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] != s[end])
		return (0);

	return is_palindrome_helper(s, start + 1, end - 1);
}

/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: The string
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = str_len(s);

	if (len <= 1)
		return (1);

	return is_palindrome_helper(s, 0, len - 1);
}
