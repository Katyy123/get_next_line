/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:51:53 by cfiliber          #+#    #+#             */
/*   Updated: 2021/05/10 18:52:49 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	void	*ptr;
	size_t	tot_size;

	tot_size = sizeof(const char) * (ft_strlen(s1) + 1);
	ptr = malloc(tot_size);
	if (!(ptr))
		return (0);
	ft_memcpy(ptr, s1, tot_size);
	return (ptr);
}

char	*ft_lines_split(char *stat_arr, char **line, ssize_t byte_read)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (stat_arr[i])
	{
		if (stat_arr[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(stat_arr))
	{
		*line = ft_substr(stat_arr, 0, i);
		tmp = ft_substr(stat_arr, i + 1, ft_strlen(stat_arr));
		free(stat_arr);
		stat_arr = ft_strdup(tmp);
		free(tmp);
	}
	else if (byte_read == 0)
	{
		*line = stat_arr;
		stat_arr = NULL;
	}
	return (stat_arr);
}

char	*ft_store_line(char *buf, char *stat_arr)
{
	char			*tmp;

	if (stat_arr)
	{
		tmp = ft_strjoin(stat_arr, buf);
		free(stat_arr);
		stat_arr = ft_strdup(tmp);
		free(tmp);
	}
	else
		stat_arr = ft_strdup(buf);
	return (stat_arr);
}

int	get_next_line(int fd, char **line)
{
	static char	*stat_arr[4096];
	char		buf[BUFFER_SIZE + 1];
	ssize_t		byte_read;

	byte_read = 1;
	while (byte_read)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == 0 && !stat_arr[fd])
		{
			*line = ft_strdup("");
			return (byte_read);
		}
		if (byte_read == -1)
			return (-1);
		buf[byte_read] = '\0';
		stat_arr[fd] = ft_store_line(buf, stat_arr[fd]);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	stat_arr[fd] = ft_lines_split(stat_arr[fd], line, byte_read);
	if (byte_read <= 0 && !stat_arr[fd])
		return (byte_read);
	return (1);
}
