/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:58:22 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/18 15:38:31 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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

char	*get_cmd(char **envp, char *cmd)
{
	int		i;
	char	*path;
	char	**split_path;
	char	*with_slash;
	char	*path_n_cmd;
	
	i = 0;
	path = get_path(envp);
	split_path = ft_split(path, ':');
	while (split_path[i])
	{
		with_slash = ft_strjoin(split_path[i], "/");
		path_n_cmd = ft_strjoin(with_slash, cmd);
		free(with_slash);
		if (access(path_n_cmd, X_OK) == 0)
		{
			free_split(split_path);
			return (path_n_cmd);
		}
		free(path_n_cmd);
		i++;
	}
	free_split(split_path);
	return (NULL);
}

