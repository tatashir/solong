/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:26:07 by tatashir          #+#    #+#             */
/*   Updated: 2023/04/21 22:04:14 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_goal(t_solong *sl)
{
	t_track	track;
	int		y;

	y = 0;
	track.line = malloc(sizeof(char *) * sl->row);
	if (track.line == NULL)
		exit_error(ERROR_MALLOC);
	while (y < sl->row)
	{
		track.line[y] = ft_strdup(sl->line[y]);
		if (track.line[y] == NULL)
			error_malloc_array(track.line, y);
		y++;
	}
	track.x = sl->x;
	track.y = sl->y;
	track.line[track.y][track.x] = '0';
	if (!(dfs_goal(track.y, track.x, &track)))
		error_map(track.line, sl->row, PLAYABLE_GOAL);
	free_array(track.line, sl->row);
}

void	check_collect(t_solong *sl)
{
	t_track	track;
	int		y;

	y = 0;
	track.line = malloc(sizeof(char *) * sl->row);
	if (track.line == NULL)
		exit_error(ERROR_MALLOC);
	while (y < sl->row)
	{
		track.line[y] = ft_strdup(sl->line[y]);
		if (track.line[y] == NULL)
			error_malloc_array(track.line, y);
		y++;
	}
	track.x = sl->x;
	track.y = sl->y;
	track.line[track.y][track.x] = '0';
	track.c_cnt = sl->c_cnt;
	if (!(dfs_collect(track.y, track.x, &track)))
		error_map(track.line, sl->row, PLAYABLE_COLLECT);
	free_array(track.line, sl->row);
}

void	check_playable(t_solong *sl)
{
	check_goal(sl);
	check_collect(sl);
}
