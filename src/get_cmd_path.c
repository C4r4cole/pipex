/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:58:22 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/21 15:36:24 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}
char	*check_cmd(char *cmd)
{
	if (!cmd)
	{
		write(2, "command not found\n", 19);
		exit(127);
	}
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	return (0);
}

char	*get_cmd(char **envp, char *cmd)
{
	int		i;
	char	*path;
	char	**split_path;
	char	*with_slash;
	char	*path_n_cmd;
	
	i = 0;
	check_cmd(cmd);
	path = get_path(envp);
	if (!path)
		return (NULL);
	split_path = ft_split(path, ':');
	while (split_path[i])
	{
		with_slash = ft_strjoin(split_path[i], "/");
		path_n_cmd = ft_strjoin(with_slash, cmd);
		free(with_slash);
		if (access(path_n_cmd, X_OK) == 0)
			return (free_split(split_path), path_n_cmd);
		free(path_n_cmd);
		i++;
	}
	free_split(split_path);
	return (NULL);
}

