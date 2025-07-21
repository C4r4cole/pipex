/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:58:18 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/21 17:36:31 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_code_err(int status)
{
	int	code;

	if (WIFEXITED(status))
	{
		code = WEXITSTATUS(status);
		return (code);
	}
	return (0);
}

int	second_fork(int *fd, char **args, char **envp, int pid1)
{
	int	pid2;
	int	status1;
	int	status2;

	pid2 = fork();
	if (pid2 == -1)
	{
		perror("fork2");
		exit(EXIT_FAILURE);
	}
	if (pid2 == 0)
	{
		child2_process(fd, args, envp);
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, &status1, 0);
		waitpid(pid2, &status2, 0);
		return (get_code_err(status2));
	}
	return (0);
}

int	create_pipe(char **args, char **envp)
{
	int	fd[2];
	int	pid1;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork1");
		exit(EXIT_FAILURE);
	}
	if (pid1 == 0)
	{
		child1_process(fd, args, envp);
	}
	else
		return (second_fork(fd, args, envp, pid1));
	return (0);
}
