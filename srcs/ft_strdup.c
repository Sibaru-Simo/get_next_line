/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidna_7 <who??@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:22:00 by sidna_7           #+#    #+#             */
/*   Updated: 2025/09/19 16:27:48 by sidna_7          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

char	*ft_strdup(char const *s)
{
	size_t	len;
	size_t	i;
	char	*d;

	i = 0;
	len = ft_strlen(s);
	d = malloc(len + 1);
	if (!d)
		return (NULL);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
