/*
 * File: 2-main.c
 * Auth: Bundi Victor
 *
 * /

#include <stdio.h>
#include <stdlib.h>


/*
 * main - Prints the name of the file of the program
 *        was compiled from, followed by a new line.
 *
 * Return: Always 0.
 */
int _putchar(char c);

void print_filename(const char *str)
{
    if (*str != '\0')
    {
        _putchar(*str);
        print_filename(str + 1);
    }
}

int main(void)
{
    char *filename = __FILE__;

    print_filename(filename);
    _putchar('\n');

    return 0;
}

int _putchar(char c)
{
    return write(1, &c, 1);
}
