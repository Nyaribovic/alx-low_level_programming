/**
 * Auth: Bundi Victor
 * File: 0-binary_to_uint.c
 */

#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string of 0 and 1 chars.
 *
 * Description: This function converts a binary string @b to an
 * unsigned int. It iterates through the binary string, validating
 * each character to be '0' or '1' and accumulating the integer value.
 *
 * Return: If @b is NULL or contains characters other than '0' or '1' - 0.
 *         Otherwise - the converted number.
 */
unsigned int binary_to_uint(const char *b)
{
	if (b == NULL)
		return (0);

	unsigned int num = 0;

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);
		num = num * 2 + (*b - '0');
		b++;
	}

	return (num);
}
