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
		free_var(line);
		return (0);
	}
	free_var(line);
	return (1);
}

int check_split(char *str, char **split)
{
	int		i;

	i = 0;
	if (!split)
		return (0);
	while (split[i] != NULL)
		i++;
	if (i != 3)
		return (0);
	if (ft_strcmp(str, split[0]))
		return (0);
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
		free_var(line);
		return (0);
	}
  if(!(split = ft_strsplit(line, ' ')))
	{
		free_var(line);
		return (0);
	}
	if(check_split("Plateau", split))
	{
		info->map_y = ft_atoi(split[1]);
		info->map_x = ft_atoi(split[2]);
	}
	else
	{
		free_arr(split);
		free_var(line);
		return (0);
	}
	free_arr(split);
	free_var(line);
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
	if (get_next_line(0, &line) < 1)
		return (0);
	free_var(line);
	while ( num_y < info->map_y && get_next_line(0, &line) > 0)
	{
		if (ft_isdigit(line[0]))
		{
			temp = ft_strjoin(map, &line[4]);
			free_var(map);
			map = ft_strjoin(temp, "\n");
			free_var(temp);
			temp = NULL;
			num_y++;
		}
		free_var(line);
	}
	if(num_y == info->map_y)
	{
			if (!(info->map = ft_strsplit(map, '\n')))
				return (0);
	}
	else
	{
		free_var(temp);
		free_var(map);
		return (0);
	}
	free_var(temp);
	free_var(map);
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
	if(get_next_line(0, &line) < 1)
		return (0);
  if(!(split = ft_strsplit(line, ' ')))
	{
		free_var(line);
		return (0);
	}
	free_var(line);
	if(check_split("Piece", split))
	{
		piece->piece_y = ft_atoi(split[1]);
		piece->piece_x = ft_atoi(split[2]);
	}
	else
	{
		free_arr(split);
		return (0);
	}
	free_arr(split);
	while (get_next_line(0, &line) > 0)
	{
		temp = ft_strjoin(piece_temp, line);
		free_var(piece_temp);
		piece_temp = ft_strjoin(temp, "\n");
		free_var(temp);
		temp = NULL;
		num_y++;
		if (num_y == piece->piece_y)
			break ;
		free_var(line);
	}
	if(!(piece->piece = ft_strsplit(piece_temp, '\n')))
	{
		free_var(line);
		return (0);
	}
	free_var(piece_temp);
	free_var(line);
	return (1);
}