/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <lpan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:37:20 by lpan              #+#    #+#             */
/*   Updated: 2019/05/14 14:37:22 by lpan             ###   ########.fr       */
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

void	print_res(int a, int b)
{
	ft_putnbr(a);
	ft_putchar(' ');
	ft_putnbr(b);
	ft_putchar('\n');
}
