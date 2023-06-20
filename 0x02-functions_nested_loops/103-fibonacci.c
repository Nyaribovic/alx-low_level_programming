/*
 * File: 103-fibonacci.c
 * Auth: Nyaribo
 */

#include <stdio.h>

/**
 * main - Prints the sum of the even-valued terms 
 *        terms not exceeding 4000000,
 *        followed by a new line.
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long fib1 = 0, fib2 = 1, fibsum;
	float tot_sum;

	while (1)
	{
		fibsum = fib1 + fib2;
		if (fibsum > 4000000)
			break;

		if ((fibsum % 2) == 0)
			tot_sum += fibsum;

		fib1 = fib2;
		fib2 = fibsum;
	}
	printf("%.0f\n", tot_sum);

	return (0);
}
