#include "main.h"

/**
 * append_text_to_file - appends a text at the end of a file.
 * @filename: A pointer to the name of the file to append to
 * @text_content: The string to append to the file
 *
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int j, k, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
		while (text_content[len])
			len++;
	j = open(filename, O_WRONLY | O_APPEND);
	if (j < 0)
		return (-1);

	if (text_content != NULL)
	{
		k = write(j, text_content, len);
		if (k != len)
			return (-1);
	}

	close(j);

	return (1);
}
