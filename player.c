/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <lpan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:47:08 by lpan              #+#    #+#             */
/*   Updated: 2019/05/13 16:47:09 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

static int		check_line(t_info *info, int y, char c)
{
	int		x;

	x = 0;
	while (x < info->map_x)
	{
		if (info->map[y][x] == c || info->map[y][x] == ft_tolower(c))
			return (1);
		x++;
	}
	return (0);
}

static int		check_enemy_inline(t_info *info)
{
	int		y;
	int		x;

	y = info->map_y - 1;
	while (y > 0)
	{
		x = info->map_x - 1;
		while (x > 0)
		{
			if (info->map[y][x] == info->player)
			{
				if (check_line(info, y, info->enemy) == 1)
					return (1);
				else
					return (0);
			}
			x--;
		}
		y--;
	}
	return (0);
}

static int		check_top_line(t_info *info)
{
	int		x;

	x = 0;
	while (x < info->map_x)
	{
		if (info->map[0][x] == info->player)
		{
			return (1);
		}
		x++;
	}
	return (0);
}

int				player(t_info *info, t_piece *piece)
{
	info->fail_place = 0;
	if(info->map == 0)
	{
		if(get_map(info) == 0)
			return (0);
		get_start_position_enemy(info);
		get_start_position_player(info);
	}
	else
	{
		if(get_map(info) == 0)
			return (0);
	}
	if(!(get_piece(piece)))
		return (0);
	if(info->startpoint_player <= info->startpoint_enemy)
	{
		if (check_enemy_inline(info) == 1 && check_top_line(info) == 0)
			place_top(info, piece);
		else
			place_bot(info, piece);
		if (info->fail_place == 1)
			place_bot(info, piece);
	}
	else
	{
		if (check_enemy_inline(info) == 1 && check_top_line(info) == 0)
			place_bot(info, piece);
		else
			place_top(info, piece);
		if (info->fail_place == 1)
			place_bot(info, piece);
	}
	if (info->finish == 1)
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
		return (0);
	}
	free_map_piece(info, piece);
	return (1);
}
