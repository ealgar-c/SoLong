/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:14:22 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/01 18:03:36 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static void	check_leaks(void)
{
	system("leaks -q so_long");
}

int	close_game(t_solong *gameinfo)
{
	int	i;

	i = 0;
	while (gameinfo->map[i++])
	{
		free(gameinfo->map[i]);
	}
	free(gameinfo->map);
	mlx_destroy_window(gameinfo->mlx_ptr, gameinfo->window_ptr);
	mlx_clear_window(gameinfo->mlx_ptr, gameinfo->window_ptr);
/* 	free(gameinfo->mlx_ptr);
	free(gameinfo->map);
	free(gameinfo->coin);
	free(gameinfo->floor);
	free(gameinfo->player);
	free(gameinfo->obs);
	free(gameinfo->exit); */
	atexit(check_leaks);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	moveplayer(int keycode, t_solong *gameinfo)
{
	if (keycode == W_KEY)
		w_movement(gameinfo);
	if (keycode == A_KEY)
		a_movement(gameinfo);
	if (keycode == S_KEY)
		s_movement(gameinfo);
	if (keycode == D_KEY)
		d_movement(gameinfo);
}

static int	key_handler(int keycode, t_solong *gameinfo)
{
	if (keycode == Q_KEY || keycode == ESCAPE_KEY)
		close_game(gameinfo);
	if (keycode == W_KEY || keycode == A_KEY
		|| keycode == S_KEY || keycode == D_KEY)
		moveplayer(keycode, gameinfo);

	return (0);
}

void	manage_loop(t_solong *gameinfo)
{
	mlx_key_hook(gameinfo->window_ptr, key_handler, gameinfo);
	mlx_hook(gameinfo->window_ptr, 17, 0, close_game, gameinfo);
	mlx_loop(gameinfo->mlx_ptr);
}
