/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:47:18 by secros            #+#    #+#             */
/*   Updated: 2024/11/24 23:22:30 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.h"

void	display_shoot(WINDOW *win, t_bullet **shoot)
{
	t_bullet *bull = *shoot;
	t_bullet *prev = NULL;
	void *pt;

	while (bull)
	{
		if (bull->origin)
			mvwaddch(win, bull->pos.y, bull->pos.x++, 'o');
		else
			mvwaddch(win, bull->pos.y, bull->pos.x--, '+');
		if (bull->pos.x >= getmaxx(win) - 2 || (bull->life <= 0) || bull->pos.x <= 1)
		{
			pt = bull;
			if (prev)
				prev->next = bull->next;
			else
				*shoot = bull->next;
			bull = NULL;
			free(pt);
		}
		else
		{
			prev = bull;
			bull = bull->next;
		}
	}
}

void	display_type(WINDOW *win, t_entity *current, t_data *data)
{
	int max_x = getmaxx(win);

	int	i;

	i = 0;
	if (current->class == 1)
    {
        if (current->wait_time == 0)
        {
            mvwaddstr(win, current->pos.y, current->pos.x--, ENEMY_1);
            current->wait_time = 5;
        }
        else
        {
            mvwaddstr(win, current->pos.y, current->pos.x, ENEMY_1);
            current->wait_time--;
        }
    }
    else if (current->class == 2)
    {
        if (current->wait_time == 0)
        {
            mvwaddstr(win, current->pos.y, current->pos.x--, ENEMY_2);
            current->wait_time = 12;
        }
        else
        {
            mvwaddstr(win, current->pos.y, current->pos.x, ENEMY_2);
            current->wait_time--;
        }
    }
    else if (current->class == 3)
    {
        if (current->wait_time == 0 && current->pos.x > max_x -20)
        {
            mvwaddstr(win, current->pos.y, current->pos.x--, ENEMY_3);
            current->wait_time = 8;
        }
        else
        {
            mvwaddstr(win, current->pos.y, current->pos.x, ENEMY_3);
            current->wait_time--;
			if (current->wait_time < 0)
			{
				current->wait_time = 25;
				shooting(current->pos, 0, data);
			}
        }
    }
}

void	display_enemy(WINDOW *win, t_entity **enemy, t_data *data)
{
	t_entity *current = *enemy;
	t_entity *prev = NULL;
	void *pt;

	while (current)
	{
		display_type(win, current, data);
		if (current->pos.x <= 1 || current->life <= 0)
		{
			if (current->life <= 0)
				data->score += current->class * 10;
			else
				data->score -= current->class * 10;
			pt = current;
			if (prev)
				prev->next = current->next;
			else
				*enemy = current->next;
			current = NULL;
			free(pt);
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

void	display_player(WINDOW *win, t_data *data)
{
	int i = 0;
	char *player[] = PLAYER_S;
	if (data->player.life <= 0)
		return ;
	while (player[i])
		mvwaddstr(win, data->player.pos.y - 1 + i, data->player.pos.x - 1, player[i++]);
}

void	display_background(WINDOW *win, t_data *data)
{
	int patern = 0;
	static int back_size = 0;
	const char back[] = BACK;
	int x = 1;

	if (!back_size)
		back_size = ft_strlen(BACK);
	data->back_off = (data->back_off +1) % back_size;
	while (x < data->window.sizex - 1)
	{
		patern = (data->back_off + x) % (back_size - 1);
		mvwaddch(win, data->window.sizey - 2, x, back[patern]);
		mvwaddch(win, 2, x, back[patern]);
		x++;
	}
}

void	display_win(WINDOW *win, t_data *data)
{
	werase(win);
	box(win, 0, 0);
	mvwprintw(win, 1, 1, "Score %d", data->score);
	display_background(win, data);
	display_player(win, data);
	display_enemy(win, &data->enemy, data);
	display_shoot(win, &data->shoot);
	wrefresh(win);
}
