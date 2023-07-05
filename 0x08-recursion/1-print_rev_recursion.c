#include "main.h"
#include <stdio.h>

/**
 * _print_rev_recursion - Prints a string in reverse.
 * @s: The string to be printed.
 */
void _print_rev_recursion(char *s)
{
    if (*s == '\0')
    {
        return;  /* Base case: End of string*/
    }

    _print_rev_recursion(s + 1);  /* Recursive call with the next character */

    _putchar(*(s)); 
}
