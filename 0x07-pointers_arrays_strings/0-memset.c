#include "main.h"
#include <stdio.h> 

/**
  * _memset - Fill memory with a constant byte
  * @s: memory area to fill
  * @b: constant byte to fill
  * @n: bytes of memory area to fill
  *
  * Return: the memory area filled
  */
char *_memset(char *s, char b, unsigned int n)
{
 	char *s_start = s;
    	while (n > 0) {
        	*s++ = b;
        	n--;
    		}
	    return s_start;
}

