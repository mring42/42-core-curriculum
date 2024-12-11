#include <stdlib.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	static char buff[BUFFER_SIZE + 1];
	static int i = 0, n = 0;
	char *line = NULL;
	int len = 0;
	while (1)
	{
		char *tmp;

		if (i >= n)
		{
			n = read(fd, buff, BUFFER_SIZE);
			if (n <= 0)
				break ;
			i = 0;
		}
		tmp = malloc(len + 2);
		if (!tmp)
		{
			free(line);
			return (NULL);
		}
		for (int j = 0; j < len; ++j)
			tmp[j] = line[j];
		tmp[len++] = buff[i];
		tmp[len] = '\0';
		free(line);
		line = tmp;
		if (buff[i++] == '\n')
			break ;
	}
	return (n > 0 || len > 1) ? line : (free(line), NULL);
}