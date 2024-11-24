/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 05:27:57 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 05:52:52 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H
# define MIN_LINES 40
# define MIN_COLS 80

# include <ncurses.h>

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
	QUIT
}	t_context;

typedef struct s_enginectx
{
	WINDOW		*windows[WIN_NB];
	t_context	context;
	int			lines;
	int			cols;
	int			score;

}	t_enginectx;

extern t_enginectx	enginectx;

void	init_enginectx(void);
void	engineloop(void);
void	destroy_engine(void);

void	menuloop(void);
void	gameloop(void);
void	statloop(void);

#endif
