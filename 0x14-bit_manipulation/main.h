#ifndef MAIN_H
#define MAIN_H

/*
 * File: main.h
 * Auth: Bundi Victor
 * Desc: Header file containing prototypes for functions
 *       in the 0x14-bit_manipulation directory.
 */

int _putchar(char c);
int clear_bit(unsigned long int *n, unsigned int index);
int get_bit(unsigned long int n, unsigned int index);
int get_endianness(void);
int set_bit(unsigned long int *n, unsigned int index);
unsigned int binary_to_uint(const char *b);
unsigned int flip_bits(unsigned long int n, unsigned long int m);
void print_binary(unsigned long int n);

#endif /* MAIN_H */
