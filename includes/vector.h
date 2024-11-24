/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:46:50 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/23 20:52:40 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector
{
	int		x;
	int		y;
	void	(*set)(struct s_vector*, int, int);
} t_vector;

void		vector_set(t_vector *v, int x, int y);
t_vector	new_vec(int x, int y);

#endif
