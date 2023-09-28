/*
 * Auth: Bundi Victor
 * File: 1-print_binary.c
 */

#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	int bit_count = sizeof(n) * 8;
	int leading_zeros = 1;

	while (bit_count--)
	{
		if (n & (1UL << bit_count))
		{
			leading_zeros = 0;
			_putchar('1');
		}
		else if (!leading_zeros)
		{
			_putchar('0');
		}
	}
	if (leading_zeros)
		_putchar('0');
}
