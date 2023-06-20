/*
 * File: 11-print_to_98.c
 * Auth: Nyaribo
 */

#include <stdio.h>

/**
 * prints all natural numbers from n to 98, followed by a new line
 *              
 * 
 */
void print_to_98(int n)
{
	if (n >= 98)
	{
		while (n > 98)
			printf("%d, ", n--);
		printf("%d\n", n);
	}

	else
	{
		while (n < 98)
			printf("%d, ", n++);
		printf("%d\n", n);
	}
}
