/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:58:18 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/18 18:23:24 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_process(int *fd, char **args, char **envp)
{
	int	fd_infile;
	
	fd_infile = read_from_infile(args[0]);
	dup2(fd_infile, STDIN_FILENO);
	close(fd_infile);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execute_cmd(args[1], envp);
	exit(0);
}

void	child2_process(int *fd, char **args, char **envp)
{
	int	fd_outfile;
	
	fd_outfile = write_on_outfile(args[3]);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_outfile, STDOUT_FILENO);
	close(fd_outfile);
	close(fd[1]);
	close(fd[0]);
	execute_cmd(args[2], envp);
	exit(0);
}

void	second_fork(int *fd, char **args, char **envp, int pid1)
{
	int pid2;
	int	status1;
	int	status2;
	
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

int	create_pipe(char **args, char **envp)
{
	int fd[2];
	int	pid1;

	
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
		second_fork(fd, args, envp, pid1);
	return (0);
}
