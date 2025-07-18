/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:03:08 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/17 16:27:11 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	execute_cmd(char *args, char **envp)
{
	char	*cmd;
	char	**split_cmd;
	char	**cmd_options;

	split_cmd = ft_split(args, ' '); // ne pas oublier tous les free !!!!!!
	cmd_options = &split_cmd[1];
	cmd = get_cmd(envp, split_cmd[0]);
	ft_printf("Start of execve call %s:\n", cmd);
	ft_printf("=====================================\n");
	if (execve(cmd, &split_cmd[0], cmd_options) == -1)
	{
		perror("Could not execute execve");
	}
	ft_printf("This shoud never be visible");
}
