#include "../include/cub3d.h"

//This function indicates player position: North, East, West, South (NEWS)
int	is_news(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

int	is_wall(char c)
{
	if (c == '1' | c == '0')
		return (1);
	return (0);
}

void	game_map_content(t_game *g)
{
	int		nb_player;
	int		i;
	int		j;

	i = 0;
	nb_player = 0;
	while (g->map_copy[i])
	{
		j = 0;
		while (g->map_copy[i][j])
		{
			if (is_wall(g->map_copy[i][j]) || is_news(g->map_copy[i][j]))
			{
				if (is_news(g->map_copy[i][j]))
					nb_player++;
			}
			else
				errmsg(ERR_CONTENT, 1, g);
			j++;
		}
		i++;
	}
	if (nb_player < 1 || nb_player > 1)
		errmsg(ERR_CONTENT, 1, g);
}

void	game_content_validation(t_game *game)
{
	game_map_content(game);
}