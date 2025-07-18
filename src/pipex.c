/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:58:18 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/17 19:07:31 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child1_process(int *fd, char **args, char **envp)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	execute_cmd(args[1], envp);
	close(fd[1]);
	exit(0);
}

void	child2_process(int *fd, char **args, char **envp)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	execute_cmd(args[2], envp);
	close(fd[0]);
	exit(0);
}

int	create_pipe(char **args, char **envp)
{
	int fd[2];
	int	pid1;
	int pid2;
	int	status1;
	int	status2;
	
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork1");
		exit(1);
	}
	if (pid1 == 0)
	{
		child1_process(fd, args, envp);
	}
	else
	{
		pid2 = fork();
		if (pid2 == -1)
		{
			perror("fork2");
			exit(1);
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
		}
	}
	return (0);
}
