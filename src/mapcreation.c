/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcreation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:44:03 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/06 14:57:26 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static void	get_player_position(t_solong *gameinfo)
{
	int	x;
	int	y;

	x = 0;
	while (x < gameinfo->i)
	{
		y = 0;
		while (y < gameinfo->j)
		{
			if (gameinfo->map[x][y] == 'P')
			{
				gameinfo->pl_x = x;
				gameinfo->pl_y = y;
				break ;
			}
			y++;
		}
		x++;
	}
}

void	get_map(int fd, t_solong *gameinfo)
{
	char	*line;
	char	*new_line;
	char	*tmp_line;

	line = get_next_line(fd);
	gameinfo->j = ft_strlen(line) - 1;
	gameinfo->i = 1;
	new_line = get_next_line(fd);
	tmp_line = ft_strdup("");
	while (new_line)
	{
		free(tmp_line);
		tmp_line = ft_strjoin(line, new_line);
		if (gameinfo->i == 1)
			free(line);
		free(new_line);
		line = tmp_line;
		new_line = get_next_line(fd);
		gameinfo->i++;
	}
	free(new_line);
	free(line);
	gameinfo->map = ft_split(line, '\n');
	get_player_position(gameinfo);
}
