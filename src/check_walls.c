/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:22:48 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/02 15:25:55 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static bool	top_row(t_solong *gameinfo)
{
	int	j_aux;

	j_aux = 0;
	while (j_aux < gameinfo->j)
	{
		if (gameinfo->map[0][j_aux] == '1')
			j_aux++;
		else
			return (false);
	}
	return (true);
}

static bool	bot_row(t_solong *gameinfo)
{
	int	j_aux;

	j_aux = 0;
	while (j_aux < gameinfo->j)
	{
		if (gameinfo->map[gameinfo->i - 1][j_aux] == '1')
			j_aux++;
		else
			return (false);
	}
	return (true);
}

static bool	first_col(t_solong *gameinfo)
{
	int	i_aux;

	i_aux = 0;
	while (i_aux < gameinfo->i)
	{
		if (gameinfo->map[i_aux][0] == '1')
			i_aux++;
		else
			return (false);
	}
	return (true);
}

static bool	last_col(t_solong *gameinfo)
{
	int	i_aux;

	i_aux = 0;
	while (i_aux < gameinfo->i)
	{
		if (gameinfo->map[i_aux][gameinfo->j - 1] == '1')
			i_aux++;
		else
			return (false);
	}
	return (true);
}

bool	check_walls(t_solong *gameinfo)
{
	if (top_row(gameinfo))
		if (bot_row(gameinfo))
			if (first_col(gameinfo))
				if (last_col(gameinfo))
					return (true);
	return (false);
}
