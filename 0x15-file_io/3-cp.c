#include "main.h"
/**
* err97 - exit with code 97
*/

void err97(void)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}

/**
* err98 - exit with code 98
* @ptr: pointer
*/

void err98(char *ptr)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", ptr);
	exit(98);
}

/**
* err99 - exit with code 99
* @ptr: pointer
*/

void err99(char *ptr)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", ptr);
	exit(99);
}

/**
* err100 - exit with code 100
* @a: variable
*/
void err100(int a)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", a);
	exit(100);
}

/**
* main - program that copies the content of a file to another file
* @argc: argument count
* @argv: argument vector
* Return: the copies content of a file
*/
int main(int argc, char *argv[])
{
	int inputFd, outputFd, cloIn, cloOu;
	ssize_t numRead;
	char buf[1024];

	if (argc != 3)
		err97();
	if (argv[1] == NULL)
		err98(argv[1]);
	inputFd = open(argv[1], O_RDONLY);
	if (inputFd == -1)
		err98(argv[1]);
	outputFd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (outputFd == -1)
		err99(argv[2]);
	numRead = read(inputFd, buf, 1024);
	if (numRead == -1)
		err98(argv[1]);
	write(outputFd, buf, numRead);
	cloIn = close(inputFd);
	if (cloIn == -1)
		err100(inputFd);
	cloOu = close(outputFd);
	if (cloOu == -1)
		err100(outputFd);
return (0);
}
