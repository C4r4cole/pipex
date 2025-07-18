/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:58:08 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/17 17:08:13 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

void	read_from_infile(char *infile);
void	write_on_outfile(char *outfile);
void	execute_cmd(char *args, char **envp);
int		create_pipe(char **args, char **envp);
void	child1_process(int *fd, char **args, char **envp);
void	child2_process(int *fd, char **args, char **envp);
char	*get_path(char **envp);
char	*get_cmd(char **envp, char *cmd);

#endif