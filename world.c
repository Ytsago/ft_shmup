/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:10:49 by secros            #+#    #+#             */
/*   Updated: 2024/11/23 12:59:53 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ncurses.h>
#include <pthread.h>

typedef struct s_loc
{
	int x;
	int	y;
} t_loc;

void	*fire(void *arg)
{
	t_loc pos = *(t_loc*) arg;
	free(arg);
	pos.x += 2;
	addch('-');
	refresh();
	while (pos.y < 100)
	{	
		insch(' ');
		refresh();
		move(pos.y, pos.x++);

		napms(5);
	}
	return (NULL);
}

int main()
{
	int key;
	t_loc	*pos;
	pthread_t shoot; 
	pos = malloc(sizeof(t_loc));
	pos->x = 5;
	pos->y = 5;
	initscr();
	while (pos->x < 20)
	{
		move(pos->y, pos->x);
		addstr("=>");
		refresh();
		key = getch();
		deleteln();
		refresh();
		if (key == 'w')
			pos->y--;
		else if(key == 's')
			pos->y++;
		else if (key == 'a')
			pos->x--;
		else if (key == 'd')
			pos->x++;
		else if (key == ' ')
		{
			t_loc *bullet_pos = malloc(sizeof(t_loc));
			*bullet_pos = *pos;
			pthread_create(&shoot, NULL, fire, bullet_pos);
			pthread_detach(shoot);
		}
		else
			break;
	}
	endwin();
}