#include "main.h"

#define USAGE "Usage: cp file_from file_to\n"
#define ERR_NOREAD "Error: Can't read from file %s\n"
#define ERR_NOWRITE "Error: Can't write to %s\n"
#define ERR_NOCLOSE "Error: Can't close fd %d\n"
#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)

/**
 * main - program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 1 on success 0 on failure
 */
int main(int ac, char **av)
{
	int fm_fd = 0, t_fd = 0;
	ssize_t b;
	char buffer[READ_BUF_SIZE];

	if (ac != 3)
		dprintf(STDERR_FILENO, USAGE), exit(97);
	fm_fd = open(av[1], O_RDONLY);
	if (fm_fd == -1)
		dprintf(STDERR_FILENO, ERR_NOREAD, av[1]), exit(98);
	t_fd = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
	if (t_fd == -1)
		dprintf(STDERR_FILENO, ERR_NOWRITE, av[2]), exit(99);

	while ((b = read(fm_fd, buffer, READ_BUF_SIZE)) > 0)
		if (write(t_fd, buffer, b) != b)
			dprintf(STDERR_FILENO, ERR_NOWRITE, av[2]), exit(99);
	if (b == -1)
		dprintf(STDERR_FILENO, ERR_NOREAD, av[1]), exit(98);

	fm_fd = close(fm_fd);
	t_fd = close(t_fd);
	if (fm_fd)
		dprintf(STDERR_FILENO, ERR_NOCLOSE, fm_fd), exit(100);
	if (t_fd)
		dprintf(STDERR_FILENO, ERR_NOCLOSE, fm_fd), exit(100);

	return (EXIT_SUCCESS);
}

