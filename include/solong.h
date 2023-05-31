/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:48:53 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/05/31 18:56:36 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
// # include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define ESCAPE_KEY 53
# define Q_KEY 12
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

typedef struct s_solong
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*player;
	void	*floor;
	void	*obs;
	void	*coin;
	void	*exit;
	char	**map;
	int		i;
	int		j;
	int		pl_x;
	int		pl_y;
	int		c_to_get;
	int		firstprint;
	int		playermovs;
}	t_solong;

char	**get_map(int fd, t_solong *gameinfo);
void	create_window(t_solong *gameinfo);
void	manage_loop(t_solong *gameinfo);
void	wind_images(t_solong *gameinfo);
void	w_movement(t_solong *gameinfo);
void	a_movement(t_solong *gameinfo);
void	s_movement(t_solong *gameinfo);
void	d_movement(t_solong *gameinfo);
bool	mapcheck(t_solong *gameinfo);
bool	check_walls(t_solong *gameinfo);
#endif