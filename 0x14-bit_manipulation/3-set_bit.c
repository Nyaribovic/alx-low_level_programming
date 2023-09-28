/*
 * Auth: Bundi Victor
 * File: 3-set_bit.c
 */
#include "main.h"

/**
 * set_bit - Sets the value of a bit at a given index to 1.
 * @n: A pointer to the number containing the bit.
 * @index: The index to set the value at - indices start at 0.
 *
 * Return: If an error occurs (index out of range) - -1.
 *         Otherwise - 1.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n |= (1UL << index);

	return (1);
}
