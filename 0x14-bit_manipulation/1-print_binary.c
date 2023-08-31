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
	if (n > 1)
		print_binary(n >> 1); /* Recursive call to print higher-order bits*/

	_putchar((n & 1) + '0'); /*Print the current least significant bit*/
}
