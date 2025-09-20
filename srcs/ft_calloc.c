/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidna_7 <who??@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 18:10:09 by sidna_7           #+#    #+#             */
/*   Updated: 2025/09/19 19:00:48 by sidna_7          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

void	ft_memset(void *s, int c, size_t size)
{
	size_t	i;
	char	*d;

	i = 0;
	d = s;
	while (i < size)
	{
		d[i] = (char)c;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	total;

	total = count * size;
	if (size != 0 && total / size != count)
		return (NULL);
	s = ft_malloc(total);
	if (!s)
		return (NULL);
	ft_memset(s, 0, total);
	return (s);
}
