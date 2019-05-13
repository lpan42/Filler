/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkplace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <lpan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:45:56 by lpan              #+#    #+#             */
/*   Updated: 2019/05/13 16:45:58 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

static int	checkplace_piece(t_info *info, t_piece *piece, int x, int y)
{
	if (x > info->map_x || x < 0)
		return (0);
	if (y > info->map_y || y < 0)
		return (0);
	if (x + piece->piece_x > info->map_x)
		return (0);
	if (y + piece->piece_y > info->map_y)
		return (0);
	return (1);
}

static int	checkplace_cover(t_info *info, t_piece *piece, int x, int y)
{
	int		i;
	int		j;
	int		temp;
	int		count;

	i = -1;
	temp = x;
	count = 0;
	while (++i < piece->piece_y)
	{
		j = -1;
		x = temp;
		while (++j < piece->piece_x)
		{
			if (info->player == 'O')
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'O')
					count++;
			if (info->player == 'X')
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'X')
					count++;
			x++;
		}
		y++;
	}
	return ((count > 1) ? 0 : 1);
}

static int	checkpace_enemy(t_info *info, t_piece *piece, int x, int y)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	temp = x;
	while (i < piece->piece_y)
	{
		j = 0;
		x = temp;
		while (j < piece->piece_x)
		{
			if (info->player == 'O')
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'X')
					return (0);
			if (info->player == 'X')
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'O')
					return (0);
			j++;
			x++;
		}
		i++;
		y++;
	}
	return (1);
}

int			checkplace(t_info *info, t_piece *piece, int x, int y)
{
	if (checkplace_piece(info, piece, x, y) == 0)
		return (0);
	if (checkplace_cover(info, piece, x, y) == 0)
		return (0);
	if (checkpace_enemy(info, piece, x, y) == 0)
		return (0);
	return (1);
}
