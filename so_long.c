/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:17:21 by tatashir          #+#    #+#             */
/*   Updated: 2023/04/30 19:40:59 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_solong	solong;
	t_map		map;

	check_pre(argc, argv);
	file_handling(&map, argv[1]);
	check_map(&map);
	set_map_to_solong(&map, &solong);
	initialize(&solong);
	check_playable(&solong);
	draw_item(&solong);
	mlx_hook(solong.win, X_EVENT_KEY_RELEASE, 0, &key_press, &solong);
	mlx_hook(solong.win, X_EVENT_KEY_EXIT, 0, &exit_solong, &solong);
	mlx_loop(solong.mlx);
	return (0);
}

// __attribute((destructor))
// static void destructor() {
//     system("leaks -q so_long");
// }

// ./so_long ./map/1.ber
