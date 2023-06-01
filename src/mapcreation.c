/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcreation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:44:03 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/06/01 19:13:24 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

/* static void	check_leaks(void)
{
	system("leaks -q so_long");
} */

void	get_map(int fd, t_solong *gameinfo)
{
	char	*line;
	char	*new_line;

	line = get_next_line(fd);
	gameinfo->j = ft_strlen(line) - 1;
	gameinfo->i = 1;
	new_line = get_next_line(fd);
	while (new_line)
	{
		line = ft_strjoin(line, new_line);
		free(new_line);
		new_line = get_next_line(fd);
		gameinfo->i++;
	}
	free(new_line);
	free(line);
	gameinfo->map = ft_split(line, '\n');
}
