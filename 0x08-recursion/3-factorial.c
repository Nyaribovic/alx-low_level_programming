#include "main.h"
#include <stdio.h>

/**
 * factorial - Returns the factorial of a given number.
 * @n: The number to find the factorial of.
 *
 * Return: If n > 0 - the factorial of n.
 *         If n < 0 - 1 to indicate an error.
 */
int factorial(int n) {
    if (n < 0) {
        return -1;  // Error: Invalid input
    }

    if (n == 0) {
        return 1;  // Base case: factorial of 0 is 1
    }

    return n * factorial(n - 1);  // Recursive call with n-1
}

