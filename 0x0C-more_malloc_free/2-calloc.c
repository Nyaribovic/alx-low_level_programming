#include "main.h"
#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array of a certain number
 *           of elements each of an inputted byte size.
 * @nmemb: The number of elements.
 * @size: The byte size of each array element.
 *
 * Return: If nmemb = 0, size = 0, or the function fails - NULL.
 *         Otherwise - a pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
    void *ptr;
    unsigned int total_size;

    if (nmemb == 0 || size == 0)
        return (NULL);

    total_size = nmemb * size;

    ptr = malloc(total_size);
    if (ptr == NULL)
        return (NULL);

    char *char_ptr = ptr;
    unsigned int i;
    for (i = 0; i < total_size; i++)
        char_ptr[i] = '\0';

    return (ptr);
}
