/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowconfig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:54:16 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/06 15:06:19 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static void	create_imgs(t_solong *gameinfo)
{
	int	w;

	w = 64;
	gameinfo->player = mlx_xpm_file_to_image(gameinfo->mlx_ptr,
			"sprites/isaac.xpm", &w, &w);
	gameinfo->floor = mlx_xpm_file_to_image(gameinfo->mlx_ptr,
			"sprites/floor.xpm", &w, &w);
	gameinfo->obs = mlx_xpm_file_to_image(gameinfo->mlx_ptr,
			"sprites/wall.xpm", &w, &w);
	gameinfo->coin = mlx_xpm_file_to_image(gameinfo->mlx_ptr,
			"sprites/coin.xpm", &w, &w);
	gameinfo->exit = mlx_xpm_file_to_image(gameinfo->mlx_ptr,
			"sprites/door.xpm", &w, &w);
}

static void	img_parser(t_solong *gameinfo, int x, int y)
{
	mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr,
		gameinfo->floor, y * 64, x * 64);
	if (gameinfo->map[x][y] == 'P')
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr,
			gameinfo->player, y * 64, x * 64);
	else if (gameinfo->map[x][y] == '1')
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr,
			gameinfo->obs, y * 64, x * 64);
	else if (gameinfo->map[x][y] == 'C')
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr,
			gameinfo->coin, y * 64, x * 64);
	else if (gameinfo->map[x][y] == 'E')
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr,
			gameinfo->exit, y * 64, x * 64);
}

void	wind_images(t_solong *gameinfo)
{
	int			x;
	int			y;

	x = 0;
	create_imgs(gameinfo);
	while (x < gameinfo->i)
	{
		y = 0;
		while (y < gameinfo->j)
		{
			img_parser(gameinfo, x, y);
			y++;
		}
		x++;
	}
}

void	create_window(t_solong *gameinfo)
{
	gameinfo->mlx_ptr = mlx_init();
	gameinfo->window_ptr = mlx_new_window(gameinfo->mlx_ptr,
			gameinfo->j * 64, gameinfo->i * 64, "So Long");
	wind_images(gameinfo);
}
