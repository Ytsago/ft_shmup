/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:09:54 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 04:13:36 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_DATA_H
# define GAME_DATA_H
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
} t_context;

typedef struct s_gamedata
{
	WINDOW		*windows[WIN_NB];
	t_context	context;
	int			lines;
	int			cols;

} t_gamedata;

extern t_gamedata	gamedata;

#endif
