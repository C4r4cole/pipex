/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_infile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:46:15 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/16 11:04:46 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	read_from_infile(void)
{
	int	fd;

	fd = open("infile", O_RDONLY | O_CREAT, 0777);
	dup2(fd, STDIN_FILENO);
	close(fd);
}
