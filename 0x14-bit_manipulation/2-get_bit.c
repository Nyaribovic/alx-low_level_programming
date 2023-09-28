/*
 * Auth: Bundi Victor
 * File: 2-get_bit.c
 */

#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given index.
 * @n: The number.
 * @index: The index of the bit to get, starting from 0.
 *
 * Return: If an error occurs (index out of range) - -1.
 *         Otherwise - The value of the bit at index (0 or 1).
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	if ((n & (1UL << index)) == 0)
		return (0);

	return (1);
}
