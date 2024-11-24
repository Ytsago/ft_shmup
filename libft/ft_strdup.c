/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:30:13 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/14 09:37:13 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = ft_calloc(sizeof(char), (ft_strlen(src) + 1));
	while (dest && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
