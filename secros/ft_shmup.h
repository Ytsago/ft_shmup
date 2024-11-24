/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shmup.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:47:29 by secros            #+#    #+#             */
/*   Updated: 2024/11/24 20:05:39 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHMUP_H
# define FT_SHMUP_H

#include <stdlib.h>
#include <ncurses.h>

# define PLAYER_S {"  -=:|\\", "-=:{[@]}=>", "  -=:|/", NULL}
# define ENEMY_1 "<o>"
# define BACK "*      .      +       "

typedef struct s_pos
{
	int				x;
	int				y;
} 					t_pos;

typedef struct 		s_bullet
{
	int				origin;
	t_pos			pos;
	struct s_bullet *next;
}					t_bullet;

typedef struct 		s_entity
{
	t_pos			pos;
	int				class;
	int				life;
	int				wait_time;
	struct s_entity *next;
}					t_entity;


typedef struct s_win
{
	int	sizex;
	int sizey;
}		t_win;

typedef struct s_data
{
	int			back_off;
	int			score;
	t_win		window;
	t_entity	player;
	t_bullet	*shoot;
	t_entity	*enemy;
} 				t_data;

void	display_shoot(WINDOW *win, t_bullet **shoot);
void	display_win(WINDOW *win, t_data *data);
void	lstadd_front(t_bullet **shoot, t_bullet *new_bull);
void	*first_wave(t_data *data, int wait);
void	lstadd_front_enti(t_entity **enemy, t_entity *new_en);
void	display_enemy(WINDOW *win, t_entity **enemy);

size_t	ft_strlen(const char *s);

/*

/|:
\|:

<o>

<|\
<|/

*/
#endif    