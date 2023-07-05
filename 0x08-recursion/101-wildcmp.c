#include "main.h"
#include <stdio.h>

/**
 * wildcmp - Compares two strings and checks if they can be considered identical
 * @s1: The first string
 * @s2: The second string with special character *
 *
 * Return: 1 if identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return 1; /* Both strings are empty, considered identical */

	if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0')
			return 1; /* s2 ends with *, considered identical */

		if (*s1 != '\0' && wildcmp(s1 + 1, s2) == 1)
			return 1; /* * matches one or more characters in s1 */

		if (wildcmp(s1, s2 + 1) == 1)
			return 1; /* * matches an empty string */

		return 0; /* * matches nothing */
	}

	if (*s1 != '\0' && (*s1 == *s2 || *s2 == '?'))
		return wildcmp(s1 + 1, s2 + 1); /* Characters match, check next ones */

	return 0; /* Characters don't match */
}

