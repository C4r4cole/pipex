/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:58:13 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/16 14:48:54 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv)
{
	char	**args;
	char	*infile;
	char	*outfile;
	
	args = argv + 1;
	if (argc != 4)
		write(2, "Error\n", 6);
	else
	{
		infile = args[0];
		outfile = args[2]; //a changer par 3 quand j'aurai implemente la deuxieme commande
		if (args[0])
		{
			read_from_infile(infile);
			write_on_outfile(outfile);
		}
		execute_cmd(args);
	}
	return (0);
}
