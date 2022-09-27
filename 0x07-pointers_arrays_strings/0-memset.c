#include "main.h"

/**
 * _memset - fills a mem block with a constant byte
 * @s: address to memory block
 * @b: char to be used
 * @n: number of bytes to be used
 *
 * Return: Pointer to the mem block
 */

char *_memset(char *s, char b, unsigned int n)
{
	while (n)
	{
		s[n - 1] = b;
		n--;
	}
	return (s);
}
