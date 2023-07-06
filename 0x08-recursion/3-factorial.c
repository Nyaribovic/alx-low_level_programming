#include "main.h"
#include <stdio.h>

/**
 * factorial - Calculates the factorial of a given number
 * @n: The number for which factorial is calculated
 *
 * Return: Factorial of n, or -1 if n is negative
 */
int factorial(int n)
{
	/* Base case: factorial of 0 is 1 */
	if (n == 1)
		return(1);

	/* Error case: n is negative */
	else if (n < 0)
		return (-1);

	/* Recursive case: calculate factorial */
	n *= factorial(n - 1);
	
	return(n);
}
