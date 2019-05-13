/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <lpan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:46:28 by lpan              #+#    #+#             */
/*   Updated: 2019/05/13 16:46:30 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		get_map_xy(t_info *info)
{
	char	*line;
	char	**split;

	if (get_next_line(0, &line) < 1)
		return (0);
	if (!(split = ft_strsplit(line, ' ')))
	{
		free_var(line);
		return (0);
	}
	if (check_split("Plateau", split))
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

int		get_player(t_info *info)
{
	char	*line;

	if (get_next_line(0, &line) < 1)
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

void	get_start_position_player(t_info *info)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < info->map_y)
	{
		x = 0;
		while (x < info->map_x)
		{
			if (info->map[y][x] == info->player)
			{
				info->startpoint_player = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	get_start_position_enemy(t_info *info)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < info->map_y)
	{
		x = 0;
		while (x < info->map_x)
		{
			if (info->map[y][x] == info->enemy)
			{
				info->startpoint_enemy = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int		main(void)
{
	t_info	info;
	t_piece	piece;

	initiate_struct(&info, &piece);
	if (!get_player(&info))
		return (0);
	if (!get_map_xy(&info))
		return (0);
	while (1)
		if (player(&info, &piece) == 0)
			break ;
	free_map_piece(&info, &piece);
}
