/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:03:08 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/16 14:14:50 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	execute_cmd(char **args)
{
	char	*cmd_path;
	char	*cmd1;
	char	**split_cmd1;
	// char	**split_cmd2;
	char	**envv;

	split_cmd1 = split_cmd(args[1]);
	envv = &split_cmd1[1];
	cmd_path = "/usr/bin/";
	cmd1 = ft_strjoin(cmd_path, split_cmd1[0]);
	ft_printf("Start of execve call %s:\n", cmd1);
	ft_printf("=====================================\n");
	if (execve(cmd1, &split_cmd1[0], envv) == -1)
	{
		perror("Could not execute execve");
	}
	ft_printf("This shoud never be visible");
}
