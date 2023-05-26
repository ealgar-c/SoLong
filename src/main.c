/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:47:40 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/05/26 10:16:08 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
}

int	ft_close(t_mlxvars *mlxvars)
{
	mlx_destroy_window(mlxvars->mlx_ptr, mlxvars->window_ptr);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_mlxvars	mlxvars;
	int			fd;
	char		**map;
	int			i;
	void		*isaac_img;
	int			width;
	int			length;

	width = 32;
	length = 32;
	i = 0;
	if (argc != 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	map = malloc(sizeof(char *) * 5);
	if (fd == -1)
	{
		ft_printf("Error\n");
		return (0);
	}
	while (i < 5)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	mlxvars.mlx_ptr = mlx_init();
	mlxvars.window_ptr = mlx_new_window(mlxvars.mlx_ptr, 500, 500, "Hello world!");
	isaac_img = mlx_xpm_file_to_image(mlxvars.mlx_ptr, "sprites/isaac.xpm", &width, &length);
	mlx_put_image_to_window(mlxvars.mlx_ptr, mlxvars.window_ptr, isaac_img, 0, 0);
	mlx_loop(mlxvars.mlx_ptr);
	mlx_key_hook(mlxvars.window_ptr, &ft_close, &mlxvars);
}
