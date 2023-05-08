#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * error_exit - Prints an error message and exits with a specific code.
 * @code: The exit code.
 * @message: The error message to print.
 * @filename: The name of the file related to the error.
 */
void error_exit(int code, const char *message, const char *filename)
{
	dprintf(STDERR_FILENO, "%s: %s", message, filename);
	exit(code);
}

/**
 * cp - Copies the content of one file to another file.
 * @file_from: The source file.
 * @file_to: The destination file.
 */
void cp(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char buffer[1024];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file", file_from);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_exit(99, "Error: Can't write to", file_to);

	while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
			error_exit(99, "Error: Can't write to", file_to);
	}

	if (bytes_read == -1)
		error_exit(98, "Error: Can't read from file", file_from);

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd", file_from);

	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd", file_to);
}

/**
 * main - Entry point.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 *
 * Return: 0 on success, or the appropriate error code on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	cp(argv[1], argv[2]);

	return (0);
}
