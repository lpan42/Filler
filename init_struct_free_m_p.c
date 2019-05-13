/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <lpan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:46:19 by lpan              #+#    #+#             */
/*   Updated: 2019/05/13 16:46:21 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void	initiate_struct(t_info *info, t_piece *piece)
{
	info->player = 0;
	info->enemy = 0;
	info->map_y = 0;
	info->map_x = 0;
	info->map = NULL;
	info->fail_place = 0;
	info->finish = 0;
	info->startpoint_player = 0;
	info->startpoint_enemy = 0;
	piece->piece_y = 0;
	piece->piece_x = 0;
	piece->piece = NULL;
}

static void	free_map(t_info *info)
{
	int i;

	i = 0;
	while (info->map[i])
	{
		free(info->map[i]);
		i++;
	}
	free(info->map);
}

static void	free_piece(t_piece *piece)
{
	int i;

	i = 0;
	while (piece->piece[i])
	{
		free(piece->piece[i]);
		i++;
	}
	free(piece->piece);
}

void		free_var(void *var)
{
	if (var != NULL)
		free(var);
}

void		free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void		free_map_piece(t_info *info, t_piece *piece)
{
	if (info->map != NULL)
	{
		free_map(info);
		info->map = NULL;
	}
	if (piece->piece != NULL)
	{
		free_piece(piece);
		piece->piece = NULL;
	}
}
