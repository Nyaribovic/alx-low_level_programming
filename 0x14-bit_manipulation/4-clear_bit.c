/*
 * Auth: Bundi Victor
 * File: 4-clear_bit.c
 */

#include "main.h"

/**
 * clear_bit - Sets the value of a bit at a given index to 0.
 * @n: A pointer to the number containing the bit.
 * @index: The index to set the value at - indices start at 0.
 *
 * Return: If an error occurs (index out of range) - -1.
 *         Otherwise - 1.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n &= ~(1UL << index); /*Clear the bit at the given index to 0*/ 

	return (1);
}
