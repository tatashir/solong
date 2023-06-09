/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:37:37 by tatashir          #+#    #+#             */
/*   Updated: 2023/04/30 19:40:03 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_item(t_solong *solong, void *item, int w, int h);

void	draw_item(t_solong *solong)
{
	int	i;
	int	j;

	i = 0;
	while (i < solong->row)
	{
		j = 0;
		while (j < solong->col)
		{
			if (solong->line[i][j] == '1')
				put_item(solong, solong->wall, j * BASE, i * BASE);
			else if (solong->line[i][j] == '0')
				put_item(solong, solong->space, j * BASE, i * BASE);
			else if (solong->line[i][j] == 'C')
				put_item(solong, solong->collect, j * BASE, i * BASE);
			else if (solong->line[i][j] == 'P')
				put_item(solong, solong->player, j * BASE, i * BASE);
			else if (solong->line[i][j] == 'E')
				put_item(solong, solong->goal, j * BASE, i * BASE);
			else if (solong->line[i][j] == 'N')
				put_item(solong, solong->ongoal, j * BASE, i * BASE);
			j++;
		}
		i++;
	}
}

static void	put_item(t_solong *solong, void *item, int w, int h)
{
	mlx_put_image_to_window(solong->mlx, solong->win, item, w, h);
}
