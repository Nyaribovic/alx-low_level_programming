/*
 * Auth: Bundi Victor
 * File: 5-flip_bits.c
 */

#include "main.h"

/**
 * flip_bits - Counts the number of bits needed to be flipped
 *             to get from one number to another.
 * @n: The starting number.
 * @m: The target number.
 *
 * Return: The number of bits that need to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int bit_count = 0;

	while (xor_result > 0)
	{
		bit_count += (xor_result & 1); 
		xor_result >>= 1; 
	}

	return (bit_count);
}
