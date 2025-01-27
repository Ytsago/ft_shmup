/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:01:13 by secros            #+#    #+#             */
/*   Updated: 2024/11/24 23:28:43 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.h"

void	shooting(t_pos pos, int me, t_data *data)
{
	t_bullet *bullet = malloc(sizeof(t_bullet));
	static int flipflop = -1;
	if (!bullet)
		return;
	if (me)
	{
		bullet->pos.x = pos.x + 5;
		bullet->pos.y = pos.y + flipflop;
		bullet->origin = 1;
		bullet->life = 1;
		flipflop *= -1;
	}
	else
	{
		bullet->pos.x = pos.x -2;
		bullet->pos.y = pos.y;
		bullet->origin = 0;
		bullet->life = 1;
	}
		lstadd_front(&data->shoot, bullet);
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
		shooting(data->player.pos, 1, data);
	if (input == 27)
		return (1);
	return (0);
}		

static void	check_player_collisions(t_data *data)
{
	t_bullet	*bullets;
	t_entity	*enemies;

	bullets = data->shoot;
	enemies = data->enemy;
	while (bullets)
	{
		if ((data->player.pos.x == bullets->pos.x)
				&& (data->player.pos.y == bullets->pos.y)
				&& (bullets->origin == 0))
		{
			data->player.life--;
			bullets->life = -1;
			break;
		}
		bullets = bullets->next;
	}
	while (enemies)
	{
		if ((data->player.pos.x == enemies->pos.x)
				&& (data->player.pos.y == enemies->pos.y))
		{
			data->player.life--;
			enemies->life = -1;
			break;
		}
		enemies = enemies->next;
	}
}

static void	check_enemy_collisions(t_data *data)
{
	t_bullet	*bullets;
	t_entity	*enemies;

	bullets = data->shoot;
	while (bullets)
	{
		enemies = data->enemy;
		while (enemies)
		{
			if ((bullets->pos.x == enemies->pos.x)
					&& (bullets->pos.y == enemies->pos.y))
			{
				enemies->life--;
				bullets->life = -1;
			}
			enemies = enemies->next;
		}
		bullets = bullets->next;
	}
}

void	collisions(t_data *data)
{
	check_player_collisions(data);
	check_enemy_collisions(data);
}

void	engine(t_data *data, WINDOW *win)
{
	int wait = 0;
	int	exit;

	while (1)
	{
		exit = user_input(data);
		display_win(win, data);
		napms(25);
		first_wave(data, wait++);
		collisions(data);
		if (wait > 1000)
			wait = 0;
		if(exit || data->player.life <= 0)
		{
			ft_data_destroy(data);
			break;
		}
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

	data->window.sizex = getmaxx(*win);
	data->window.sizey = getmaxy(*win);

	data->player.pos.x = 5;
	data->player.pos.y = data->window.sizey / 2;
	data->player.life = 5;


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
