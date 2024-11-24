/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 05:27:57 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 10:39:25 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H
# define MIN_LINES 40
# define MIN_COLS 80
# define ENGINE_SPEED 25

# include <ncurses.h>
# include "game.h"
# include "game_data.h"
# define MENU_WIN 0
# define GAME_WIN 1
# define STAT_WIN 2
# define CTRLS_WIN 3
# define LVL_WIN 4
# define ALERT_WIN 5
# define WIN_NB 6

typedef enum e_context
{
	MENU,
	GAME,
	QUIT,
	ALERT
}	t_context;

typedef struct s_enginectx
{
	WINDOW		*windows[WIN_NB];
	t_context	context;
	int			lines;
	int			cols;
	t_gamedata	game;
}	t_enginectx;

extern t_enginectx	enginectx;

void	init_enginectx(void);
void	engineloop(void);
void	destroy_engine(void);

void	menuloop(void);
void	gameloop(void);
void	statloop(void);

#endif
