/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 05:26:16 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 07:05:03 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# define SCROLLER "*      .      +       "
# define SCROLL_LEN 22
# define ESC_KEY 127

void	init_game(void);

typedef struct s_gamedata
{
	int	scroller;
	int	lines;
	int	cols;
}	t_gamedata;

#endif
