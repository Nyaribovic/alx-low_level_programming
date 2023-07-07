#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins to
 * make change for an amount of money
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (Success), 1 (Error)
 */
int main(int argc, char *argv[]) 
{
    if (argc != 2) 
	{
        printf("Error\n");
        return (1);
	}

    int cents = atoi(argv[1]);
    if (cents < 0) 
	{
        printf("0\n");
        return (0);
	}

    int coins[] = {25, 10, 5, 2, 1};
    int num_coins = 0;
    int i = 0;

    while (cents > 0) 
	{
        num_coins += cents / coins[i];
        cents %= coins[i];
        i++;
	}

    printf("%d\n", num_coins);

    return (0);
}
