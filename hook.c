/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:34:56 by tatashir          #+#    #+#             */
/*   Updated: 2023/04/29 16:42:15 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_solong *sl)
{
	char	point;

	if (sl->line[sl->y][sl->x] == 'N')
		point = 'E';
	else
		point = 'X';
	if (keycode == KEY_W)
		move_w(sl, point);
	else if (keycode == KEY_S)
		move_s(sl, point);
	else if (keycode == KEY_A)
		move_a(sl, point);
	else if (keycode == KEY_D)
		move_d(sl, point);
	else if (keycode == KEY_ESC)
		exit_solong(sl);
	return (0);
}

int	exit_solong(t_solong *sl)
{
	mlx_destroy_window(sl->mlx, sl->win);
	free_array(sl->line, sl->row);
	exit(0);
}
