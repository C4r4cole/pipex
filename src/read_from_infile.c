/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_infile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:46:15 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/21 15:29:48 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	read_from_infile(char *infile)
{
	int	fd_infile;

	fd_infile = open(infile, O_RDONLY, 0644);
	if (fd_infile == -1)
	{
		write(2, "no such file or directory: ", 28);
		write(2, infile, ft_strlen(infile));
		write(2, "\n", 2);
	}
	return (fd_infile);
}
