#include "includes/filler.h"

int get_player(t_info *info)
{
    char	*line;  

	if(get_next_line(0, &line) < 1)
		return (0);
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
	else
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

int get_map_xy(t_info *info)
{
    char    *line;
    char	**split;

	if(get_next_line(0, &line) < 1)
		return (0);
	if(line[0] != 'P')
	{
		free(line);
		return (0);
	}
    if(!(split = ft_strsplit(line, ' ')))
		return (0);
    info->map_y = ft_atoi(split[1]);
	info->map_x = ft_atoi(split[2]);
	free(line);
	return (1);
}

static int check_map(t_info *info)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if(!info->map)
		return (0);
	while (y < info->map_y - 1)
	{
		x = 0;
		while (x < info->map_x - 1)
		{
			if (info->map[y][x] != 'O' && info->map[y][x] != 'X' &&
				info->map[y][x] != '.' && info->map[y][x] != 'o' &&
				info->map[y][x] != 'x')
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
	char	*temp;
	char	*map;
	int		num_y;

	map = NULL;
	temp = NULL;
	num_y = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_isdigit(line[0]) && (line[4] == '.' || line[4] == 'O' ||
			line[4] == 'X' || line[4] == 'x' || line[4] == 'o'))
		{
			temp = map;
			map = ft_strjoin(temp, &line[4]);
			if(temp)
				free(temp);
			temp = map;
			map = ft_strjoin(temp, "\n");
			num_y++;
		}
		if (num_y == info->map_y)
			break ;
	}
	info->map = ft_strsplit(map, '\n');
	if(check_map(info) == 0)
		return(0);
	free(map);
	free(line);
	return(1);
}

int	get_piece(t_piece *piece)
{
	char	*line;
	char 	*temp;
	char	*piece_temp;
	int		num_y;
    char	**split;

	piece_temp = NULL;
	temp = NULL;
	num_y = 0;
	get_next_line(0, &line);
    split = ft_strsplit(line, ' ');
	piece->piece_y = ft_atoi(split[1]);
	piece->piece_x = ft_atoi(split[2]);
	while (get_next_line(0, &line) > 0)
	{
		temp = piece_temp;
		piece_temp = ft_strjoin(temp, line);
		if(temp)
			free(temp);
		temp = piece_temp;
		piece_temp = ft_strjoin(temp, "\n");
		num_y++;
		if (num_y == piece->piece_y)
			break ;
	}
	if(!(piece->piece = ft_strsplit(piece_temp, '\n')))
		return (0);
	free(piece_temp);
	free(line);
	return (1);
}