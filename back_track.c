/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:18:41 by terabu            #+#    #+#             */
/*   Updated: 2023/04/29 17:47:27 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	go_next(int dir, int *m, t_track *bt);

int	dfs_goal(int i, int j, t_track *bt)
{
	int	dir;
	int	m[2];

	if (bt->line[i][j] == 'E')
		return (1);
	bt->line[i][j] = 'x';
	dir = 0;
	while (dir < 4)
	{
		m[0] = i;
		m[1] = j;
		if (go_next(dir, m, bt) != -1)
		{
			if (dfs_goal(m[0], m[1], bt))
				return (1);
		}
		dir++;
	}
	return (0);
}

int	dfs_collect(int i, int j, t_track *bt)
{
	int	dir;
	int	m[2];

	if (bt->line[i][j] == 'C')
	{
		if (!(--bt->c_cnt))
			return (1);
		bt->line[i][j] = '0';
	}
	bt->line[i][j] = 'x';
	dir = 0;
	while (dir < 4)
	{
		m[0] = i;
		m[1] = j;
		if (go_next(dir, m, bt) != -1)
		{
			if (dfs_collect(m[0], m[1], bt))
				return (1);
		}
		dir++;
	}
	return (0);
}

static	int	go_next(int dir, int *m, t_track *bt)
{
	if (dir == 0)
	{
		if (!(bt->line[m[0] - 1][m[1]] == '1')
			&& !(bt->line[m[0] - 1][m[1]] == 'x'))
			return (m[0]--);
	}
	else if (dir == 1)
	{
		if (!(bt->line[m[0]][m[1] + 1] == '1')
			&& !(bt->line[m[0]][m[1] + 1] == 'x'))
			return (m[1]++);
	}
	else if (dir == 2)
	{
		if (!(bt->line[m[0] + 1][m[1]] == '1')
			&& !(bt->line[m[0] + 1][m[1]] == 'x'))
			return (m[0]++);
	}
	else if (dir == 3)
	{
		if (!(bt->line[m[0]][m[1] - 1] == '1')
			&& !(bt->line[m[0]][m[1] - 1] == 'x'))
			return (m[1]--);
	}
	return (-1);
}
