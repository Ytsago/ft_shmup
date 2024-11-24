/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shmup.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:47:29 by secros            #+#    #+#             */
/*   Updated: 2024/11/24 16:20:40 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHMUP_H
# define FT_SHMUP_H

#include <stdlib.h>
#include <ncurses.h>

# define PLAYER_S {"  -=:|\\", "-=:{[@]}=>", "  -=:|/", "\0"}
# define BACK "*      .      +       "

typedef struct s_pos
{
	int				x;
	int				y;
	struct s_pos	*next;
} 					t_pos;

typedef struct s_win
{
	int	sizex;
	int sizey;
}		t_win;

typedef struct s_data
{
	int		back_off;
	int		score;
	t_win	window;
	t_pos	player;
	t_pos	*shoot;
	t_pos	*enemy;
} 			t_data;

void	display_shoot(WINDOW *win, t_pos **shoot);
void	display_win(WINDOW *win, t_data *data);
void	lstadd_front(t_pos **shoot, t_pos *new_bull);
size_t	ft_strlen(const char *s);

/*

/|:
\|:

<o>

<|\
<|/

*/
#endif    