/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 05:32:11 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 05:33:07 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

void	printcenter(WINDOW *win, char *str);
WINDOW	*create_newwin(int height, int width, int starty, int startx);
void	destroy_win(WINDOW *win);
bool	check_for_resize(void);

void	resize_menu(void);
void	resize_game(void);
void	resize_stat(void);

#endif
