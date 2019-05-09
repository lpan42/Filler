#include "includes/filler.h"

void get_player(t_info *info)
{
    char	*line;  

	get_next_line(0, &line);
    if (ft_strstr(line, "p1"))
	{
		info->player = 'O';
		info->enemy = 'X';
	}
	else if (ft_strstr(line, "p2"))
	{
		info->player = 'X';
		info->enemy = 'O';
	}
}

void get_map_xy(t_info *info)
{
    char    *line;
    char	**split;

	get_next_line(0, &line);
    split = ft_strsplit(line, ' ');
    info->map_y = ft_atoi(split[1]);
	info->map_x = ft_atoi(split[2]);
}

static int check_map(t_info *info)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < info->map_y - 1)
	{
		x = 0;
		while(x < info->map_x - 1)
		{
			if(info->map[y][x] != 'O' && info->map[y][x] != 'X' && info->map[y][x] != '.')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	get_map(t_info *info)
{
	char	*line;
	char	*map;
	int		num_y;

	map = NULL;
	num_y = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_isdigit(line[0]))
		{
			map = ft_strjoin(map, &line[4]);
			map = ft_strjoin(map, "\n");
			num_y++;
		}
		if (num_y == info->map_y)
			break ;
	}
	info->map = ft_strsplit(map, '\n');
	free(map);
	if(check_map(info) == 0)
		return(0);
	return(1);
}

void	get_piece(t_piece *piece)
{
	char	*line;
	char	*piece_temp;
	int		num_y;
    char	**split;

	piece_temp = NULL;
	num_y = 0;
	get_next_line(0, &line);
    split = ft_strsplit(line, ' ');
	piece->piece_y = ft_atoi(split[1]);
	piece->piece_x = ft_atoi(split[2]);
	while (get_next_line(0, &line) > 0)
	{
		piece_temp = ft_strjoin(piece_temp, line);
		piece_temp = ft_strjoin(piece_temp, "\n");
		num_y++;
		if (num_y == piece->piece_y)
			break ;
	}
	piece->piece = ft_strsplit(piece_temp, '\n');
}