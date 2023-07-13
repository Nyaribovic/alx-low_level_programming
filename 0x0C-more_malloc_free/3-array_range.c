#include "main.h"
#include <stdlib.h>

/**
 * array_range - Creates an array of integers ordered
 *               from min to max, inclusive.
 * @min: The first value of the array.
 * @max: The last value of the array.
 *
 * Return: If min > max or the function fails - NULL.
 *         Otherwise - a pointer to the newly created array.
 */
int *array_range(int min, int max)
{
    if (min > max)
        return (NULL);

    int *array;
    int size = max - min + 1;

    array = malloc(sizeof(int) * size);
    if (array == NULL)
        return (NULL);

    int i;
    for (i = 0; i < size; i++)
        array[i] = min++;

    return (array);
}
