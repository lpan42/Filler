/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <lpan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:50:53 by lpan              #+#    #+#             */
/*   Updated: 2019/05/14 15:01:50 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct	s_info
{
	char		player;
	char		enemy;
	int			map_x;
	int			map_y;
	char		**map;
	int			startpoint_player;
	int			startpoint_enemy;
	int			fail_place;
	int			finish;

}				t_info;

typedef struct	s_piece
{
	int			piece_x;
	int			piece_y;
	char		**piece;
}				t_piece;

void			initiate_struct(t_info *info, t_piece *piece);
void			free_var(void *var);
void			free_arr(char **arr);
int				check_split(char *str, char **split);
void			print_res(int a, int b);
int				get_player(t_info *info);
int				get_map_xy(t_info *info);
int				get_map(t_info *info);
int				get_piece(t_piece *piece);
void			get_start_position_enemy(t_info *info);
void			get_start_position_player(t_info *info);
int				checkplace(t_info *info, t_piece *piece, int x, int y);
void			place_top(t_info *info, t_piece *piece);
void			place_bot(t_info *info, t_piece *piece);
void			place_left(t_info *info, t_piece *piece);
int				player(t_info *info, t_piece *piece);
void			free_map_piece(t_info *info, t_piece *piece);

#endif
