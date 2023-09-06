#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: -1- If the function fails or filename is NULL.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int c, w, lit = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lit = 0; text_content[lit];)
			lit++;
	}

	c = open(filename, O_WRONLY | O_APPEND);
	w = write(c, text_content, lit);

	if (c == -1 || w == -1)
		return (-1);

	close(c);

	return (1);
}
