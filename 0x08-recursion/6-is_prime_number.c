#include "main.h"
#include <stdio.h>

/**
 * @n: The number to be checked.
 * @divivisor: The divisor.
 *
 * Return: If the number is divisible - 0.
 *         If the number is not divisible - 1.
 */
int is_prime_helper(int n, int divisor) {
    if (n <= 1) {
        return 0;  // Base case: Numbers less than or equal to 1 are not prime
    }

    if (divisor * divisor > n) {
        return 1;  // Base case: Found a prime number
    }

    if (n % divisor == 0) {
        return 0;  // Base case: Found a divisor, not a prime number
    }

    return is_prime_helper(n, divisor + 1);  // Recurse with the next divisor
}

int is_prime_number(int n) {
    return is_prime_helper(n, 2);  // Call helper function with divisor starting from 2
}

