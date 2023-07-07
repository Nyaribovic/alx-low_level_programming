#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - adds two positive number
 * @argc: number of arguments
 * @argv: array of arguents
 *
 * Return: 0 (Success), or 1 (Success)
 */
int main(int argc, char *argv[]) 
{
    if (argc == 1) {
        printf("0\n");
        return (0);
    }

    int sum = 0;
    for (int i = 1; i < argc; i++) 
	{
        for (int j = 0; argv[i][j] != '\0'; j++) 
		{
            if (!isdigit(argv[i][j]))
		 {
                printf("Error\n");
                return (1);
          	  }
        }
        sum += atoi(argv[i]);
    }

    printf("%d\n", sum);

    return (0);
}
