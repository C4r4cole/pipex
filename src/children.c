/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:12:32 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/21 16:02:12 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_process(int *fd, char **args, char **envp)
{
	int	fd_infile;

	fd_infile = read_from_infile(args[0]);
	if (fd_infile == -1)
	{
		close_fd(fd, fd_infile);
		exit(EXIT_FAILURE);
	}
	else
	{
		dup2(fd_infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close_fd(fd, fd_infile);
		execute_cmd(args[1], envp);
		exit(0);
	}
}

void	child2_process(int *fd, char **args, char **envp)
{
	int	fd_outfile;

	fd_outfile = write_on_outfile(args[3]);
	if (fd_outfile == -1)
	{
		close_fd(fd, fd_outfile);
		exit(EXIT_FAILURE);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd_outfile, STDOUT_FILENO);
		close_fd(fd, fd_outfile);
		execute_cmd(args[2], envp);
		exit(0);
	}
}
