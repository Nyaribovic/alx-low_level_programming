#include "main.h"

/**
 * set_string - sets the value of a pointer to a char
 * @s: pointer to pointer we need to set to
 * @to: string to set
 */
void set_string(char **s, char *to)
{
	// Check if the pointer is already pointing to a valid memory location
    if (*s != NULL) {
        // Deallocate the previously allocated memory
        free(*s);
    }

    // Allocate memory for the new string
    *s = (char *)malloc((strlen(to) + 1) * sizeof(char));

    // Copy the contents of 'to' to the newly allocated memory
    strcpy(*s, to);
}
