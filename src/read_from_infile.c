/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_infile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:46:15 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/18 18:23:17 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	read_from_infile(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY, 0644);
	if (fd == -1)
	{
		perror(infile);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
