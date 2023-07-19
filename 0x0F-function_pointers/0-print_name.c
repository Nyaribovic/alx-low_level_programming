/*
 * File: 0-print_name.c
 * Auth: Bundi Victor
 */

#include "function_pointers.h"

/**
 * print_name - Prints a name.
 * @name: The name to be printed.
 * @f: A pointer to a function that prints a name.
 */
void print_name_recursive(char *name, void (*f)(char *));
void print_char(char *name, void (*f)(char *));
void print_name(char *name, void (*f)(char *))
{
    print_name_recursive(name, f);
}

void print_name_recursive(char *name, void (*f)(char *))
{
    if (*name) {
        print_char(name, f);
        print_name_recursive(name + 1, f);
    }
}

void print_char(char *name, void (*f)(char *))
{
    f(*name);
 }
