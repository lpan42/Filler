/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <lpan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:46:52 by lpan              #+#    #+#             */
/*   Updated: 2019/05/13 16:46:55 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

static int	cover_piece_right(t_info *info, t_piece *piece, int y, int x)
{
	int		i;
	int		j;

	i = piece->piece_y - 1;
	while (i >= 0)
	{
		j = piece->piece_x - 1;
		while (j >= 0)
		{
			if (piece->piece[i][j] == '*')
			{
				if (checkplace(info, piece, x - j, y - i))
				{
					ft_putnbr(y - i);
					ft_putchar(' ');
					ft_putnbr(x - j);
					ft_putchar('\n');
					return (1);
				}
			}
			j--;
		}
		i--;
	}
	return (0);
}

static int	cover_piece_left(t_info *info, t_piece *piece, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	while (i < piece->piece_y)
	{
		j = 0;
		while (j < piece->piece_x)
		{
			if (piece->piece[i][j] == '*')
			{
				if (checkplace(info, piece, x - j, y - i))
				{
					ft_putnbr(y - i);
					ft_putchar(' ');
					ft_putnbr(x - j);
					ft_putchar('\n');
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

void		place_top(t_info *info, t_piece *piece)
{
	int		y;
	int		x;

	y = 0;
	while (y < info->map_y)
	{
		x = 0;
		while (x < info->map_x)
		{
			if (info->map[y][x] == info->player)
				if (cover_piece_right(info, piece, y, x) == 1)
					return ;
			x++;
		}
		y++;
	}
	info->fail_place = 1;
}

void		place_bot(t_info *info, t_piece *piece)
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
				if (cover_piece_left(info, piece, y, x) == 1)
					return ;
			x--;
		}
		y--;
	}
	info->finish = 1;
}
