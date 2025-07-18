/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:03:08 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/18 18:23:50 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char *args, char **envp)
{
	char	*cmd;
	char	**split_cmd;
	char	**cmd_options;

	split_cmd = ft_split(args, ' ');
	cmd_options = &split_cmd[1];
	cmd = get_cmd(envp, split_cmd[0]);
	if (!cmd)
	{
		free_split(split_cmd);
		perror("command not found");
		exit(127);
	}
	if (execve(cmd, split_cmd, envp) == -1)
	{
		free_split(split_cmd);
		perror("Could not execute execve");
	}
	free(cmd);
	ft_printf("This shoud never be visible");
}
