/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <lpan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:46:38 by lpan              #+#    #+#             */
/*   Updated: 2019/05/13 16:46:40 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		check_split(char *str, char **split)
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

char	*get_map2(t_info *info)
{
	char	*temp;
	char	*line;
	char	*map;
	int		num_y;

	map = NULL;
	temp = NULL;
	num_y = 0;
	while (num_y < info->map_y && get_next_line(0, &line) > 0)
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
	if (num_y == info->map_y)
		return (map);
	return (NULL);
}

int		get_map(t_info *info)
{
	char	*line;
	char	*map;

	map = NULL;
	if (get_next_line(0, &line) < 1)
		return (0);
	free_var(line);
	map = get_map2(info);
	if (map)
	{
		if (!(info->map = ft_strsplit(map, '\n')))
			return (0);
		free_var(map);
		return (1);
	}
	return (0);
}

int		get_piece2(int num_y, t_piece *piece)
{
	char	*temp;
	char	*line;
	char	*piece_temp;

	piece_temp = NULL;
	temp = NULL;
	while (num_y < piece->piece_y && get_next_line(0, &line) > 0)
	{
		temp = ft_strjoin(piece_temp, line);
		free_var(piece_temp);
		piece_temp = ft_strjoin(temp, "\n");
		free_var(temp);
		temp = NULL;
		free_var(line);
		num_y++;
	}
	if (!(piece->piece = ft_strsplit(piece_temp, '\n')))
	{
		free_var(piece_temp);
		return (0);
	}
	free_var(piece_temp);
	return (1);
}

int		get_piece(t_piece *piece)
{
	char	*line;
	char	**split;
	int		num_y;

	num_y = 0;
	if (get_next_line(0, &line) < 1)
		return (0);
	if (!(split = ft_strsplit(line, ' ')))
	{
		free_var(line);
		return (0);
	}
	free_var(line);
	if (check_split("Piece", split))
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
	return (get_piece2(num_y, piece));
}
