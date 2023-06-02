/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:15:28 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/02 15:13:28 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static bool	check_shape(t_solong *gameinfo)
{
	int	i_aux;

	i_aux = gameinfo->i - 1;
	while (i_aux >= 0)
	{
		if (ft_strlen(gameinfo->map[i_aux]) != gameinfo->j)
			return (false);
		i_aux--;
	}
	return (true);
}

static bool	check_count(t_solong *gameinfo)
{
	int	pcount;
	int	x;
	int	y;

	pcount = 0;
	gameinfo->ecount = 0;
	gameinfo->c_to_get = 0;
	x = -1;
	while (++x < gameinfo->i)
	{
		y = -1;
		while (++y < gameinfo->j)
		{
			if (gameinfo->map[x][y] == 'P')
				pcount++;
			else if (gameinfo->map[x][y] == 'C')
				gameinfo->c_to_get++;
			else if (gameinfo->map[x][y] == 'E')
				gameinfo->ecount++;
		}
	}
	if (pcount == 1 && gameinfo->ecount == 1 && (gameinfo->c_to_get >= 1))
		return (true);
	return (false);
}

bool	mapcheck(t_solong *gameinfo)
{
	if (!check_shape(gameinfo))
	{
		ft_printf("Error:\nLa forma del mapa no es correcta.");
		return (false);
	}
	if (!check_walls(gameinfo))
	{
		ft_printf("Error:\nEl mapa no esta rodeado de muros.");
		return (false);
	}
	if (!check_count(gameinfo))
	{
		ft_printf("Error:\nEl mapa no tiene un numero correcto de objetos.");
		return (false);
	}
	if (!check_path(gameinfo))
	{
		ft_printf("Error:\nEl mapa no tiene un camino posible.");
		return (false);
	}
	return (true);
}
