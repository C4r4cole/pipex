/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:58:13 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/15 15:33:04 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(void)
{

	// int	fd;
	char	*cmd;
	char	*argv[] = {"ls", "-l", NULL};
	char	*envv[] = {NULL};

	cmd = "/usr/bin/ls";
	// fd = open("infile.txt", O_RDONLY | O_CREAT, 0777);
	ft_printf("Start of execve call %s:\n", cmd);
	ft_printf("=====================================\n");
	if (execve(cmd, argv, envv) == -1)
	{
		perror("Could not execute execve");
	}
	ft_printf("Oops, something went wrong!");
	return (0);
}