/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:27:24 by mring             #+#    #+#             */
/*   Updated: 2024/11/11 15:27:52 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int	err(char *s)
{
	while (*s)
		write(2, s++, 1);
	return (1);
}

int	cd(char **argv, int i)
{
	return (i != 2 ? err("error: cd: bad arguments\n") : chdir(argv[1]) ==
		-1 ? err("error: cd: cannot change directory to "), err(argv[1]),
		err("\n") : 0);
}

int	exec(char **argv, char **envp, int i)
{
	int	pid;

	int fd[2], status, has_pipe = argv[i] && !strcmp(argv[i], "|");
	if (has_pipe && pipe(fd) == -1)
		return (err("error: fatal\n"));
	pid = fork();
	if (!pid)
	{
		argv[i] = 0;
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1
				|| close(fd[1]) == -1))
			return (err("error: fatal\n"));
		execve(*argv, argv, envp);
		return (err("error: cannot execute "), err(*argv), err("\n"));
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1
			|| close(fd[1]) == -1))
		return (err("error: fatal\n"));
	return (WIFEXITED(status) ? WEXITSTATUS(status) : 1);
}

int	main(int argc, char **argv, char **envp)
{
	int i = 0, status = 0;
	if (argc > 1)
	{
		while (argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				i++;
			status = !strcmp(*argv, "cd") ? cd(argv, i) : (i ? exec(argv, envp,
						i) : 0);
		}
	}
	return (status);
}