/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:27:12 by tatashir          #+#    #+#             */
/*   Updated: 2023/04/30 19:41:04 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "mlx.h"
# include <fcntl.h>
# include <limits.h>
# include "library/get_next_line/get_next_line.h"
# include "library/ft_printf/ft_printf.h"

# define BASE 60

# define ERROR_ARGS			"Invalid number of command line arguments."
# define ERROR_FILE			"The file does not exist."
# define ERROR_BER			"The is not ber file."
# define ERROR_BIG_MAP		"The map is too large."
# define ERROR_EMPTY		"The map is empty."
# define ERROR_RECT			"Themap is not a rectagnle."
# define ERROR_CLOSEMAP		"The map is not escapable."
# define ERROR_WALL			"The map is not enclosed by walls."
# define ERROR_ITEM			"It is not a Item."
# define ERROR_COLLECT		"Map error."
# define ERROR_PLAYER		"There are too many players."
# define ERROR_GOAL			"There are too many goal."
# define PLAYABLE_GOAL		"The goal is unreachable."
# define PLAYABLE_COLLECT	"There are uncollectable items."

# define ERROR_MALLOC	"malloc has failed"
# define ERROR_READ		"read has failed"
# define ERROR_MLX		"mlx has failed"

# define EXTENTION		".ber"
# define MAX_FILE_ROW	999
# define MAX_MAP_COL	50
# define MAX_MAP_ROW	25
# define DIR_P			"./images/player.xpm"
# define DIR_W			"./images/wall.xpm"
# define DIR_E			"./images/empty.xpm"
# define DIR_G			"./images/goal.xpm"
# define DIR_C			"./images/collect.xpm"
# define DIR_O			"./images/on_goal.xpm"

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

typedef struct s_solong{
	void	*mlx;
	void	*win;
	int		win_w;
	int		win_h;
	int		img_wid;
	int		img_hei;
	void	*player;
	void	*space;
	void	*goal;
	void	*wall;
	void	*collect;
	void	*ongoal;
	char	*filepath;
	char	**line;
	int		row;
	int		col;
	int		x;
	int		y;
	int		m_cnt;
	int		c_cnt;
	bool	clear;
}	t_solong;

typedef struct s_map{
	int		fd;
	char	*filepath;
	char	**line;
	int		start_row;
	int		end_row;
	int		c_cnt;
	int		row;
	int		col;
}	t_map;

typedef struct s_track{
	int		x;
	int		y;
	int		c_cnt;
	char	**line;
}	t_track;

void	check_pre(int argc, char **argv);
void	check_map(t_map *map);
void	check_wall(char *s, t_map *map, int y);
void	check_item(char *s, t_map *map, int y);
void	count_mapsize(char *buf, int *set_row);

void	check_playable(t_solong *sl);
void	check_goal(t_solong *sl);
void	check_collect(t_solong *sl);
void	init_dic(int *dic);
int		dfs_goal(int i, int j, t_track *bt);
int		dfs_collect(int i, int j, t_track *bt);

void	file_handling(t_map *map, char *filepath);
void	map_rowcount(t_map *map);
void	find_map_row(t_map *map);
void	set_map_to_solong(t_map *map, t_solong *sl);
int		open_file(char *filepath);

void	initialize(t_solong *solong);
void	init_window(t_solong *s);
void	init_item(t_solong *s);
void	init_player(t_solong *s);
void	init_after_move(t_solong *sl);

void	draw_item(t_solong *solong);
// void	put_item(t_solong *solong, void *item, int w, int h);

int		key_press(int keycode, t_solong *solong);
int		exit_solong(t_solong *sl);

void	move_w(t_solong *sl, char point);
void	move_s(t_solong *sl, char point);
void	move_a(t_solong *sl, char point);
void	move_d(t_solong *sl, char point);

void	move_w_n(t_solong *sl);
void	move_s_n(t_solong *sl);
void	move_a_n(t_solong *sl);
void	move_d_n(t_solong *sl);

void	movelog(t_solong *sl);
void	error_ftprintf(char const *message);

// error
void	error_map(char **line, int row, const char *msg);
void	error_file(int fd, char *s, const char *msg);
void	error_malloc_array(char **s, int i);

// close
void	free_array(char **line, int row);
void	exit_error(const char *message);

#endif
