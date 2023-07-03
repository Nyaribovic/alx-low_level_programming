#include "main.h"
#include <stdio.h> 

/**
  * _memcpy - copy memory area
  * @dest: dest memory area
  * @src: source memory area
  * @n: bytes from memory area to copy
  *
  * Return: memory area replaced
  */
char *_memcpy(char *dest, char *src, unsigned int n) {
    char *dest_start = dest;
    while (n > 0) {
        *dest++ = *src++;
        n--;
    }
    return dest_start;
}

