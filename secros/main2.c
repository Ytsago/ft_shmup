/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:01:13 by secros            #+#    #+#             */
/*   Updated: 2024/11/24 18:54:46 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.h"

void	shooting(t_data *data, int me)
{
	t_bullet *bullet = malloc(sizeof(t_bullet));
	static int flipflop = -1;
	if (!bullet)
		return;
	if (me)
	{
		bullet->pos.x = data->player.pos.x + 5;
		bullet->pos.y = data->player.pos.y + flipflop;
		lstadd_front(&data->shoot, bullet);
		flipflop *= -1;
	}
}

int	user_input(t_data *data)
{
	int	input;
	input = getch();
	if (input == 'w' && data->player.pos.y > 4)
		data->player.pos.y--;
	if (input == 's'&& data->player.pos.y < data->window.sizey - 4)
		data->player.pos.y++;
	if (input == 'd'&& data->player.pos.x < 20)
		data->player.pos.x++;
	if (input == 'a'&& data->player.pos.x > 2)
		data->player.pos.x--;
	if (input == ' ')
		shooting(data, 1);
	if (input == 27)
		return (1);
	return (0);
}		

void	engine(t_data *data, WINDOW *win)
{
	while (1)
	{
		if(user_input(data))
			break;
		display_win(win, data);
		napms(25);
	//	if (data->enemy = NULL)
	//		enemy_spawner(data);
	}
}

void	data_init(WINDOW **win, t_data *data)
{
	initscr();
	cbreak();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, true);
	timeout(1);

	*win = newwin(40, 100, 5, 10);

	data->player.pos.x = 5;
	data->player.pos.y = 10;

	data->window.sizex = getmaxx(*win);
	data->window.sizey = getmaxy(*win);

	data->enemy =NULL;
	data->score = 0;
	data->back_off = 0;
	data->shoot = NULL;
}

int main()
{
	t_data	data;
	WINDOW *game_win;
	data_init(&game_win, &data);
	engine(&data, game_win);
	endwin();
}
