#include "main.h"

/**
* _strlen - count the lenght of a string
* @s: string to count
* Return: count
*/

int _strlen(char *s)
{
	int count, i = 0;

	count = 0;
	while (s[i] != '\0')
	{
		i++;
		count++;
	}
return (count);
}

/**
* create_file - function that creates a file
* @filename: name of file
* @text_content: content of text
* Return: 1 or -1 if its fail
*/

int create_file(const char *filename, char *text_content)
{
	int fd, wr;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	if (text_content != NULL)
	{
		wr = write(fd, text_content, _strlen(text_content));
		if (wr == (-1))
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
return (1);
}
