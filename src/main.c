/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:47:40 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/02 15:13:03 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

/* void printmap(char **map)
{
	int i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
} */

int	main(int argc, char **argv)
{
	t_solong	gameinfo;
	int			fd;

	if (argc != 2)
	{
		ft_printf("Error:\nNumero de argumentos incorrecto.");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error:\nNo se ha podido abrir el fichero.");
		return (-1);
	}
	get_map(fd, &gameinfo);
	if (!mapcheck(&gameinfo))
		return (-1);
	gameinfo.playermovs = 0;
	create_window(&gameinfo);
	manage_loop(&gameinfo);
	return (0);
}
