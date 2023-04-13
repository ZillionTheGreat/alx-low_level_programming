#include "main.h"

/**
 * create_file - Creates file
 * @filename: A pointer to the name of the created file
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int fd, i, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
		while (text_content[len])
			len++;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd < 0)
		return (-1);

	if (text_content != NULL)
	{
		i = write(fd, text_content, len);
		if (i != len)
			return (-1);
	}
	close(fd);

	return (1);
}
