/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermovement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:28:39 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/01 12:48:56 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	w_movement(t_solong *gameinfo)
{
	if (gameinfo->map[gameinfo->pl_x - 1][gameinfo->pl_y] == '0')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_x -= 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		wind_images(gameinfo);
		gameinfo->playermovs++;
		ft_printf("numero de movimientos: %i\n", gameinfo->playermovs);
	}
	else if (gameinfo->map[gameinfo->pl_x - 1][gameinfo->pl_y] == 'C')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_x -= 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		wind_images(gameinfo);
		gameinfo->c_to_get--;
		gameinfo->playermovs++;
		ft_printf("numero de movimientos: %i\n", gameinfo->playermovs);
	}
	else if (gameinfo->map[gameinfo->pl_x - 1][gameinfo->pl_y] == 'E')
	{
		if (gameinfo->c_to_get == 0)
			close_game(gameinfo);
	}
}

void	a_movement(t_solong *gameinfo)
{
	if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y - 1] == '0')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_y -= 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		wind_images(gameinfo);
		gameinfo->playermovs++;
		ft_printf("numero de movimientos: %i\n", gameinfo->playermovs);
	}
	else if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y - 1] == 'C')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_y -= 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		gameinfo->c_to_get--;
		wind_images(gameinfo);
		gameinfo->playermovs++;
		ft_printf("numero de movimientos: %i\n", gameinfo->playermovs);
	}
	else if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y - 1] == 'E')
	{
		if (gameinfo->c_to_get == 0)
			close_game(gameinfo);
	}
}

void	s_movement(t_solong *gameinfo)
{
	if (gameinfo->map[gameinfo->pl_x + 1][gameinfo->pl_y] == '0')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_x += 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		wind_images(gameinfo);
		gameinfo->playermovs++;
		ft_printf("numero de movimientos: %i\n", gameinfo->playermovs);
	}
	else if (gameinfo->map[gameinfo->pl_x + 1][gameinfo->pl_y] == 'C')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_x += 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		gameinfo->c_to_get--;
		wind_images(gameinfo);
		gameinfo->playermovs++;
		ft_printf("numero de movimientos: %i\n", gameinfo->playermovs);
	}
	else if (gameinfo->map[gameinfo->pl_x + 1][gameinfo->pl_y] == 'E')
	{
		if (gameinfo->c_to_get == 0)
			close_game(gameinfo);
	}
}

void	d_movement(t_solong *gameinfo)
{
	if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y + 1] == '0')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_y += 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		wind_images(gameinfo);
		gameinfo->playermovs++;
		ft_printf("numero de movimientos: %i\n", gameinfo->playermovs);
	}
	else if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y + 1] == 'C')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_y += 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		gameinfo->c_to_get--;
		wind_images(gameinfo);
		gameinfo->playermovs++;
		ft_printf("numero de movimientos: %i\n", gameinfo->playermovs);
	}
	else if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y + 1] == 'E')
	{
		if (gameinfo->c_to_get == 0)
			close_game(gameinfo);
	}
}
