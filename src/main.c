/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:58:13 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/18 14:26:42 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**args;
	
	args = argv + 1;
	if (argc != 5)
		write(2, "Error\n", 6);
	else
	{
		read_from_infile(args[0]);
		write_on_outfile(args[3]);
		create_pipe(args, envp);
	}
	return (0);
}
