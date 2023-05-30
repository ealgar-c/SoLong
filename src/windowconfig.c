/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowconfig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:54:16 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/05/30 19:52:46 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	imagestry(void *mlx_ptr, void *window_ptr, int i, int j, void *floor)
{
	int	x;
	int	y;

	x = 0;
	while (x <= i)
	{
		y = 0;
		while (y <= j)
		{
			mlx_put_image_to_window(mlx_ptr, window_ptr, floor, y * 64, x * 64);
			y++;
		}
		x++;
	}
}

static void	wind_images(void *mlx_ptr, void *window_ptr, int i, int j, char **map)
{
	void		*isaac;
	void		*floor;
	void		*wall;
	void		*coin;
	void		*exit;
	int			w;
	int			x;
	int			y;

	x = 0;
	w = 64;
	isaac = mlx_xpm_file_to_image(mlx_ptr, "sprites/isaac.xpm", &w, &w);
	floor = mlx_xpm_file_to_image(mlx_ptr, "sprites/floor.xpm", &w, &w);
	wall = mlx_xpm_file_to_image(mlx_ptr, "sprites/wall.xpm", &w, &w);
	coin = mlx_xpm_file_to_image(mlx_ptr, "sprites/coin.xpm", &w, &w);
	exit = mlx_xpm_file_to_image(mlx_ptr, "sprites/door.xpm", &w, &w);
	while (x < i)
	{
		y = 0;
		while (y < j)
		{
			mlx_put_image_to_window(mlx_ptr, window_ptr, floor, y * 64, x * 64);
			if (map[x][y] == 'P')
				mlx_put_image_to_window(mlx_ptr, window_ptr, isaac, y * 64, x * 64);
			else if (map[x][y] == '1')
				mlx_put_image_to_window(mlx_ptr, window_ptr, wall, y * 64, x * 64);
			else if (map[x][y] == 'C')
				mlx_put_image_to_window(mlx_ptr, window_ptr, coin, y * 64, x * 64);
			else if (map[x][y] == 'E')
				mlx_put_image_to_window(mlx_ptr, window_ptr, exit, y * 64, x * 64);
			y++;
		}
		x++;
	}
}

void	create_window(char **map, int j)
{
	void	*mlx_ptr;
	void	*window_ptr;
	int		i;

	i = 1;
	while (map[i])
		i++;
	mlx_ptr = mlx_init();
	window_ptr = mlx_new_window(mlx_ptr, j * 64, i * 64, "So Long");
	wind_images(mlx_ptr, window_ptr, i, j, map);
	mlx_loop(mlx_ptr);
}
