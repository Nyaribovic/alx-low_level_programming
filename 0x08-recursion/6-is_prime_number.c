#include "main.h"
#include <stdio.h>

/**
 * is_prime_number - Checks if a number is prime
 * @n: The number to be checked
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	int i;

	/* Edge cases: 0, 1, and negative numbers are not prime */
	if (n <= 1)
		return 0;

	/* Check for divisibility by numbers from 2 to sqrt(n) */
	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return 0; /* Not prime if divisible by i */
	}

	return 1; /* Prime number */
}
