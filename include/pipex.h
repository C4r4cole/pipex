/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:58:08 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/16 14:47:58 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>

void	read_from_infile(char *infile);
void	write_on_outfile(char *outfile);
void	execute_cmd(char **argv);
char	**split_cmd(char *args);

#endif