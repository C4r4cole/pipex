/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:03:08 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/21 19:23:05 by fmoulin          ###   ########.fr       */
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
	cmd_error_mgmt(cmd, split_cmd, envp);
	free(cmd);
}
