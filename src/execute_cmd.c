/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:03:08 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/21 14:45:10 by fmoulin          ###   ########.fr       */
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
		write(2, "command not found: ", 20);
		write(2, split_cmd[0], ft_strlen(split_cmd[0]));
		write(2, "\n", 2);
		free_split(split_cmd);
		exit(127);
	}
	if (execve(cmd, split_cmd, envp) == -1)
	{
		free_split(split_cmd);
		free(cmd);
		perror("Could not execute execve");
		exit(126);
	}
	free(cmd);
}
