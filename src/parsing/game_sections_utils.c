/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_sections_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:38:46 by anarodri          #+#    #+#             */
/*   Updated: 2023/03/14 15:38:47 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	map_longest_width(t_game *game)
{
	int	i;
	int	line;
	int	width;

	width = 0;
	i = game->map_index;
	while (game->game_copy[i])
	{
		line = ft_strlen(game->game_copy[i]);
		if (line > width)
			width = line;
		i++;
	}
	return (width);
}

int	map_first_index(char **game)
{
	int	i;
	int	j;

	i = 0;
	while (game[i])
	{
		j = 0;
		while (ft_isset(game[i][j], " "))
			j++;
		if (game[i][j] == '1' || game[i][j] == '0')
			break ;
		i++;
	}
	return (i);
}

void	game_length(t_game *game)
{
	char	*str;

	str = get_next_line(game->fd);
	if (!str)
		errmsg(ERR_EMPTY_MAP, 1, game);
	while (1)
	{
		if (!str)
			break ;
		game->total_length++;
		xfree(str);
		str = get_next_line(game->fd);
	}
	close(game->fd);
	game->fd = 0;
}

void	ft_strlcpy1(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst || !src || size == 0)
		return ;
	while (src[i])
	{
		if (src[i] == ' ')
			dst[i] = '-';
		else
			dst[i] = src[i];
		i++;
	}
	while (i < (size - 1))
		dst[i++] = '-';
	dst[i] = '\0';
}
