/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:53:32 by cfiliber          #+#    #+#             */
/*   Updated: 2021/05/10 18:54:05 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	tot_size;
	size_t	i;
	size_t	j;

	tot_size = sizeof(char const) * (ft_strlen(s1) + ft_strlen(s2) + 1);
	new_str = malloc(tot_size);
	if (!(new_str) || !s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new_str[i++] = s2[j++];
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	tot_size;
	size_t	i;

	tot_size = sizeof(char const) * (len + 1);
	s2 = malloc(tot_size);
	if (!(s2))
		return (0);
	i = start;
	while (i < (len + start) && s[i] != '\0')
	{
		s2[i - start] = s[i];
		i++;
	}
	s2[i - start] = '\0';
	return (s2);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	car;
	size_t	i;
	int		slen;
	char	*s2;

	car = (char)c;
	slen = ft_strlen(s);
	s2 = (char *)s;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == car)
			return (s2 + i);
		i++;
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	if (!dst && !src)
		return (0);
	while (n--)
	{
		s2[n] = s1[n];
	}
	return (dst);
}
