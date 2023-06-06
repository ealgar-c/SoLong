/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:59:00 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/06 15:23:10 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

char	**map_flood(char **map_cpy, int x, int y)
{
	if (map_cpy[x + 1][y] == '0' || map_cpy[x + 1][y] == 'E'
		|| map_cpy[x + 1][y] == 'C')
	{
		map_cpy[x + 1][y] = 'f';
		map_flood(map_cpy, x + 1, y);
	}
	if (map_cpy[x][y - 1] == '0' || map_cpy[x][y - 1] == 'E'
		|| map_cpy[x][y - 1] == 'C')
	{
		map_cpy[x][y - 1] = 'f';
		map_flood(map_cpy, x, y - 1);
	}
	if (map_cpy[x - 1][y] == '0' || map_cpy[x - 1][y] == 'E'
		|| map_cpy[x - 1][y] == 'C')
	{
		map_cpy[x - 1][y] = 'f';
		map_flood(map_cpy, x - 1, y);
	}
	if (map_cpy[x][y + 1] == '0' || map_cpy[x][y + 1] == 'E'
		|| map_cpy[x][y + 1] == 'C')
	{
		map_cpy[x][y + 1] = 'f';
		map_flood(map_cpy, x, y + 1);
	}
	return (map_cpy);
}

char	**map_copy(t_solong *gameinfo)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char **)(ft_calloc(sizeof(char *), (gameinfo->i + 1)));
	while (i < gameinfo->i)
	{
		copy[i] = ft_substr(gameinfo->map[i], 0, ft_strlen(gameinfo->map[i]));
		i++;
	}
	return (copy);
}

bool	check_path(t_solong *gameinfo)
{
	char	**map_cpy;
	int		x;
	int		y;
	int		coins;

	map_cpy = map_flood(map_copy(gameinfo), gameinfo->pl_x,
			gameinfo->pl_y);
	x = -1;
	gameinfo->acc_e = 0;
	coins = 0;
	while (++x < gameinfo->i - 1)
	{
		y = -1;
		while (++y < gameinfo->j - 1)
		{
			if (gameinfo->map[x][y] == 'E' && map_cpy[x][y] == 'f')
				gameinfo->acc_e = 1;
			else if (gameinfo->map[x][y] == 'C' && map_cpy[x][y] == 'f')
				coins++;
		}
	}
	if (gameinfo->acc_e == 1 && coins == gameinfo->c_to_get)
		return (true);
	return (false);
}
