/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:58:08 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/21 15:35:21 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

int		read_from_infile(char *infile);
int		write_on_outfile(char *outfile);
void	execute_cmd(char *args, char **envp);
int		create_pipe(char **args, char **envp);
void	child1_process(int *fd, char **args, char **envp);
void	child2_process(int *fd, char **args, char **envp);
char	*get_path(char **envp);
char	*get_cmd(char **envp, char *cmd);
void	free_split(char **tab);
void	close_fd(int *fd, int fd_in_out);
int		second_fork(int *fd, char **args, char **envp, int pid1);
int		get_code_err(int status);
char	*check_cmd(char *cmd);

#endif