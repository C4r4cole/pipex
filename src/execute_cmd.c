/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:03:08 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/16 11:04:15 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	execute_cmd(void)
{
	char	*cmd;
	char	*argv[] = {"cat", NULL};
	char	*envv[] = {NULL};

	cmd = "/usr/bin/cat";
	ft_printf("Start of execve call %s:\n", cmd);
	ft_printf("=====================================\n");
	if (execve(cmd, argv, envv) == -1)
	{
		perror("Could not execute execve");
	}
	ft_printf("This shoud never be visible");
}
