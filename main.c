
#include "includes/filler.h"

static void		initiate_struct(t_info *info, t_piece *piece)
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

void get_start_position_player(t_info *info)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < info->map_y)
	{
		x = 0;
		while(x < info->map_x)
		{
			if(info->map[y][x] == info->player)
			{
				info->startpoint_player = y;
				return;
			}
			x++;
		}
		y++;
	}
}

void get_start_position_enemy(t_info *info)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < info->map_y)
	{
		x = 0;
		while(x < info->map_x)
		{
			if(info->map[y][x] == info->enemy)
			{
				info->startpoint_enemy = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int				main(void)
{
	t_info	info;
	t_piece	piece;

	initiate_struct(&info, &piece);
	if(!get_player(&info))
		return (0);
    if(!get_map_xy(&info))
		return (0);
	//get_map(&info);
	// 	printf("wrongmap\n");
	// get_start_position_player(&info);
	// get_start_position_enemy(&info);
	
	// player_o(&info, &piece);
	// printf("enemy: %d\n", info.startpoint_enemy);
	// printf("player:%d\n", info.startpoint_player);
	// printf("map_x: %d\n", info.map_x);
	// printf("map_y: %d\n", info.map_y);
	while (1)
	{
		if (info.player == 'O')
			if (player_o(&info, &piece) == 0)
				break ;
		if (info.player == 'X')
			if (player_x(&info, &piece) == 0)
				break ;
	}
	free_map_piece(&info, &piece);
}