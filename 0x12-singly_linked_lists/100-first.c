#include <stdio.h>

/**
 * my_startup_function - Function to be called before main.
 * It prints the message "You're beat! and yet, you must allow,
 * I bore my house upon my back!"
 */
void my_startup_function(void) __attribute__((constructor));

/**
 * my_startup_function - Function to be called before main.
 * It prints the message "You're beat! and yet, you must allow,
 * I bore my house upon my back!"
 */
void my_startup_function(void)
{
    printf("You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}

/**
 * main - The main function.
 * It is the entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
    printf("This is the main function.\n");
    return 0;
}
