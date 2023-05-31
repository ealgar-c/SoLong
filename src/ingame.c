/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:14:22 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/05/31 18:56:03 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

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
	{
		mlx_destroy_window(gameinfo->mlx_ptr, gameinfo->window_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == W_KEY || keycode == A_KEY
		|| keycode == S_KEY || keycode == D_KEY)
	{
		moveplayer(keycode, gameinfo);
		ft_printf("numero de movimientos: %i\n", gameinfo->playermovs);
	}
	return (0);
}

void	manage_loop(t_solong *gameinfo)
{
	mlx_key_hook(gameinfo->window_ptr, key_handler, gameinfo);
	mlx_loop(gameinfo->mlx_ptr);
	free(gameinfo->mlx_ptr);
	exit(EXIT_SUCCESS);
	return ;
}
