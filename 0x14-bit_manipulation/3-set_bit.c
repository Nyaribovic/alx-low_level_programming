/*
 * Auth: Bundi Victor
 * File: 3-set_bit.c
 */

#include "main.h"

/**
 * set_bit - Sets the value of a bit at a given index to 1.
 * @n: A pointer to the number containing the bit.
 * @index: The index of the bit to set - indices start at 0.
 *
 * Return: 1 if successful, -1 if index is out of range.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
    if (index >= sizeof(unsigned long int) * 8)
        return (-1);

    *n |= (1UL << index); 

    return (1);
}
