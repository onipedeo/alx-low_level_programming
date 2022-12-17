#include "main.h"

/**
  * _strstr - locate a substring
  * @haystack: the string to search
  * @needle: the string to find
  *
  * Return: char value
  */
char *_strstr(char *haystack, char *needle)
{
	int i = 0, j = 0;

	while (haystack[i])
	{
		while (needle[j])
		{
			if (haystack[i + j] != needle[j])
			{
				break;
			}

			j++;
		}

		if (needle[j] == '\0')
		{
			return (haystack + i);
		}

		i++;
	}

	return ('\0');
}
