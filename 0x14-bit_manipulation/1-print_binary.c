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
	if (n == 0)
	{
		_putchar('0');
		return;
	}

	int bit_count = (sizeof(n) * 8) - 1;

	while (bit_count >= 0)
	{
		int bit = (n >> bit_count) & 1;
		_putchar(bit + '0');
		bit_count--;
	}
}
