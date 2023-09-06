#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: num of letters to be read
 * Return: w- if actual number of bytes read and printed or
 *	0- when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t u;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	u = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, u);

	free(buf);
	close(fd);
	return (w);
}
