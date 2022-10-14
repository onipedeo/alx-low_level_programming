#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"
/**
 * print_numbers - Entry Point
 * @separator: comma space
 * @n: elements to be printed
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list valist;
	unsigned int i;
	int num;

	va_start(valist, n);

	for (i = 0; i < n; i++)
	{
		num = va_arg(valist, int);
		printf("%d", num);

		if (i < n - 1 && separator)
			printf("%s", separator);
	}
	printf("\n");

	va_end(valist);
}
