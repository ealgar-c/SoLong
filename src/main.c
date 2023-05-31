/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:47:40 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/05/31 18:52:07 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int	main(int argc, char **argv)
{
	t_solong	gameinfo;
	int			fd;

	if (argc != 2)
	{
		perror("Error: Numero de argumentos incorrecto.");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error: No se ha podido abrir el fichero.");
		return (-1);
	}
	gameinfo.map = get_map(fd, &gameinfo);
	ft_printf("i= %i, j= %i\n", gameinfo.i, gameinfo.j);
	if (!mapcheck(&gameinfo))
	{
		perror("Error: El mapa no es correcto.");
		return (-1);
	}
	gameinfo.playermovs = 0;
	create_window(&gameinfo);
	manage_loop(&gameinfo);
	return (0);
}
