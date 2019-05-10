#include "includes/filler.h"

static void free_map(t_info *info)
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

static void free_piece(t_piece *piece)
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

void free_var(void *var)
{
	if(var != NULL)
		free(var);
}

void free_arr(char **arr)
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

void free_map_piece(t_info *info, t_piece *piece)
{
	if(info->map != NULL)
	{
		free_map(info);
		info->map = NULL;
	}
	
	if(piece->piece != NULL)
	{
		free_piece(piece);
		piece->piece = NULL;
	}
}
	
