/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_infile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:46:15 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/16 14:44:41 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	read_from_infile(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY, 0777);
	if (fd == -1)
	{
		perror(infile);
		exit(EXIT_SUCCESS);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}
