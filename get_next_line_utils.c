/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidna_7 <who??@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 08:53:58 by sidna_7           #+#    #+#             */
/*   Updated: 2025/09/28 09:55:08 by sidna_7          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(char const *s, int c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != (unsigned char)c)
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	full_len;
	char	*str;

	i = 0;
	j = 0;
	full_len = ft_strlen(s1, 0);
	full_len += ft_strlen(s2, 0);
	str = malloc(full_len + 1);
	if (!str)
		return (NULL);
	while (s1[i + j])
	{
		str[j] = s1[i + j];
		j++;
	}
	while (s2[i])
	{
		str[j + i] = s2[i];
		i++;
	}
	str[i + j] = '\0';
	return (str);
}

void	*ft_calloc(size_t count, size_t	size)
{
	char	*s;
	char	*d;
	size_t	i;
	size_t	total;

	i = 0;
	total = count * size;
	if (size != 0 && total / size != count)
		return (NULL);
	s = malloc(total);
	if (!s)
		return (NULL);
	d = s;
	while (i < total)
	{
		d[i] = 0;
		i++;
	}
	return (s);
}

char	*ft_strchr(char const *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strdup(char const *s)
{
	size_t	i;
	size_t	len;
	char	*d;

	i = 0;
	len = ft_strlen(s, 0);
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
