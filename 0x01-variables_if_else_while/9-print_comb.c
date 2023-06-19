/*
 * File: 9-print_comb.c
 * Auth: Nyaribo 
 */

#include <stdio.h>

/**
 * main - Prints all possible combinations of single-digit numbers.
 * Return: Always zero
 *
 */
int main(void)
{
	int num;

	for (num = 0; num <= 9; num++)
	{
		putchar((num % 10) + '0');
		if (num <= 9)
			continue;
	
		putchar(',');
		putchar(' ');
	}

	putchar('\n');

	return (0);
}
