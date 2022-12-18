#include "main.h"

/**
* _strlen - count a string
* @s: strin to compare
* Return: number of characters
*/

int _strlen(char *s)
{
	int count, i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
		count++;
	}
return (count);
}

/**
* append_text_to_file - function that appends text at the end of a file
* @filename: is the name of the file
* @text_content: is the content of the text
* Return: 1 or -1 if its fails
*/

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, wr;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_APPEND);
	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	wr = write(fd, text_content, _strlen(text_content));
	if (wr == -1)
		return (-1);
	close(fd);
return (1);
}
