/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidna_7 <who??@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 19:01:13 by sidna_7           #+#    #+#             */
/*   Updated: 2025/09/19 19:18:19 by sidna_7          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	full_len;
	char	*full_str;

	i = 0;
	j = 0;
	full_len = ft_strlen(s1);
	full_len += ft_strlen(s2);
	full_str = malloc(full_len + 1);
	if (!full_str)
		return (NULL);
	while (s1[i + j])
	{
		full_str[j] = s1[i + j];
		j++;
	}
	while (s2[i])
	{
		full_str[i + j] = s2[i];
		i++;
	}
	full_str[i + j] = '\0';
	return (full_str);
}
