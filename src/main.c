/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:58:13 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/21 19:51:59 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**args;

	if (argc != 5)
	{
		write(2, "Usage: ...\n", 6);	// commentaire
		return (EXIT_FAILURE);
	}
	else
	{
		args = argv + 1;
		return (create_pipe(args, envp));
	}
}
