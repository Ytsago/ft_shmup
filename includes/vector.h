/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:46:50 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 09:21:32 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec
{
	int		x;
	int		y;
	void	(*set)(struct s_vec*, int, int);
} t_vec;

void	vector_set(t_vec *v, int x, int y);
t_vec	new_vec(int x, int y);

#endif
