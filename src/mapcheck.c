/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:15:28 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/05/31 18:56:15 by ealgar-c         ###   ########.fr       */
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
	int	ecount;
	int	x;
	int	y;

	pcount = 0;
	ecount = 0;
	gameinfo->c_to_get = 0;

	x = 0;
	while (x < gameinfo->i)
	{
		y = 0;
		while (y < gameinfo->j)
		{
			if (gameinfo->map[x][y] == 'P')
				pcount++;
			else if (gameinfo->map[x][y] == 'C')
					gameinfo->c_to_get++;
			else if (gameinfo->map[x][y] == 'E')
				ecount++;
			y++;
		}
		x++;
	}
	if (pcount == 1 && ecount == 1 && (gameinfo->c_to_get >= 1))
		return (true);
	return (false);
}

bool	mapcheck(t_solong *gameinfo)
{

	if (!check_shape(gameinfo) || !check_walls(gameinfo))
	{
		return (false);
	}
	if (!check_count(gameinfo))
	{
		return (false);
	}
	return (true);
}
