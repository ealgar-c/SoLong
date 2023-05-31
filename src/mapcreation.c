/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcreation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:44:03 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/05/31 18:56:25 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

char	**get_map(int fd, t_solong *gameinfo)
{
	char	*line;
	char	*new_line;
	char	**map;

	line = get_next_line(fd);
	gameinfo->j = ft_strlen(line) - 1;
	gameinfo->i = 1;
	new_line = get_next_line(fd);
	while (new_line)
	{
		line = ft_strjoin(line, new_line);
		new_line = get_next_line(fd);
		gameinfo->i++;
	}
	map = malloc(gameinfo->i * sizeof(char *));
	map = ft_split(line, '\n');
	return (map);
}
