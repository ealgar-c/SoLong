/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcreation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:44:03 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/05/30 17:44:40 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

char	**get_map(int fd)
{
	int		j;
	int		i;
	char	*line;
	char	*new_line;
	char	**map;

	line = get_next_line(fd);
	j = ft_strlen(line);
	i = 1;
	new_line = get_next_line(fd);
	while (new_line)
	{
		line = ft_strjoin(line, new_line);
		new_line = get_next_line(fd);
		i++;
	}
	map = malloc(i * sizeof(char *));
	map = ft_split(line, '\n');
	return (map);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}
