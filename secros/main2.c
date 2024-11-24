/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:01:13 by secros            #+#    #+#             */
/*   Updated: 2024/11/24 22:43:16 by secros           ###   ########.fr       */
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
		bullet->origin = me;
		bullet->life = 1;
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

static void	check_player_collisions(t_data *data)
{
	t_bullet	*bullets;
	t_entity	*enemies;
	t_entity	player;

	bullets = data->shoot;
	enemies = data->enemy;
	player = data->player;
	while (bullets)
	{
		if ((player.pos.x == bullets->pos.x)
				&& (player.pos.y == bullets->pos.y)
				&& (bullets->origin == 0))
		{
			player.life--;
			bullets->life = -1;
			break;
		}
		bullets = bullets->next;
	}
	while (enemies)
	{
		if ((player.pos.x == enemies->pos.x)
				&& (player.pos.y == enemies->pos.y))
		{
			player.life--;
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
	while (1)
	{
		if(user_input(data))
			break;
		display_win(win, data);
		napms(25);
		first_wave(data, wait++);
		collisions(data);
		if (wait > 500)
			wait = 0;
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
