/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:23:07 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/21 19:43:15 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	no_cmd(char *cmd)
{
	if (!cmd)
	{
		write(2, "command not found\n", 19);
		exit(127);
	}

}

void	cmd_error_mgmt(char *cmd, char **split_cmd, char **envp)
{
		if (!cmd)
	{
		write(2, "command not found: ", 20);
		write(2, split_cmd[0], ft_strlen(split_cmd[0]));
		write(2, "\n", 2);
		free_split(split_cmd);
		exit(127);
	}
	if (access(cmd, X_OK) == -1)
	{
		perror(split_cmd[0]);
		free_split(split_cmd);
		free(cmd);
		exit(126);
	}
	if (execve(cmd, split_cmd, envp) == -1)
	{
		free_split(split_cmd);
		free(cmd);
		perror("Could not execute execve");
		exit(126);
	}
}