/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:41:10 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 04:33:36 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include "game_data.h"
#include <ncurses.h>
#include <string.h>
#include <stdbool.h>
#include "libft.h"

# define ESC_KEY 127
# define MIN_LINES 40
# define MIN_COLS 80

void	printcenter(WINDOW *win, char *str);
WINDOW	*create_newwin(int height, int width, int starty, int startx);
void	destroy_win(WINDOW *win);
void	init_gamedata(void);
void	destroy_engine(void);
bool	check_for_resize(void);

void	init_engine(void);
void	engineloop(void);
void	destroy_engine(void);

void	menuloop(void);
void	resize_menu(void);

void	gameloop(void);
void	resize_game(void);

void	statloop(void);
void	resize_stat(void);

#endif
