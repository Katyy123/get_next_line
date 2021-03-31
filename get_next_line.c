/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:28:26 by cfiliber          #+#    #+#             */
/*   Updated: 2021/03/31 20:19:08 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>

int	ft_count_byte()
{
	int nbyte;

	nbyte = 10;
}

int	get_next_line(int fd, char **line)
{
	size_t	nbyte_read;

	if (fd == -1 || !(line))
		return (0);
	nbyte_toread = ft_count_byte();
	nbyte_read = read(fd, *line, nbyte_toread);
	return ();
}

int	main(void)
{
	int		fd;
	char**	ptr;

	ptr[100] = "Questo e' la prima riga del file.\nQuesta e' la seconda riga. Questa e' la terza e ultima.\n";
	fd = open("file.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	write(fd, ptr, strlen(ptr));
	printf("%d\n", get_next_line(fd, ptr));
}
