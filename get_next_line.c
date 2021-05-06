/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:28:26 by cfiliber          #+#    #+#             */
/*   Updated: 2021/05/06 20:37:40 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>//need it for printf
#include <string.h>
#include <fcntl.h>//need it for open

ssize_t	ft_detect_line()
{
	ssize_t nbyte;

	
	nbyte = 4;
	return (nbyte);
}

int	get_next_line(int fd, char **line)
{
	ssize_t	nbyte_read;
	ssize_t	nbyte_toread;
	char	buf[BUFFER_SIZE + 1];

	if (fd == -1 || !(line))
		return (-1);
	nbyte_toread = ft_detect_line();
	nbyte_read = read(fd, *line, BUFFER_SIZE);
	if (nbyte_read == 0)
		return (0);
	if (nbyte_read == -1)
		return (-1);
	return (nbyte_read);
}

int	main(void)
{
	int		fd;
	char	*ptr;
	//char str[100] = "Questa e' la prima riga del file.\nQuesta e' la seconda riga.\nQuesta e' la terza e ultima.";
	//ptr = &str[0];
	fd = open("file.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	//write(fd, ptr, strlen(ptr));
	printf("%d\n", get_next_line(fd, &ptr));
}
