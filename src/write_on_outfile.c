/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_on_outfile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:52:58 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/16 11:04:49 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	write_on_outfile(void)
{
	int	fd;

	fd = open("outfile", O_WRONLY | O_CREAT, 0777);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
