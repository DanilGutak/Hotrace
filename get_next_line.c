/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:13:21 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/15 14:34:19 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*take_line(char *buf)
{
	char	*ret;
	int		z;

	z = 0;
	if (!buf[z])
		return (NULL);
	while (buf[z] && buf[z] != '\n')
		z++;
	ret = ft_calloc(z + 2, sizeof(char));
	if (!ret)
		return (NULL);
	while (z >= 0)
	{
		ret[z] = buf[z];
		z--;
	}
	return (ret);
}

char	*delete_line(char *buf)
{
	int		z;
	int		s;
	char	*ret;

	z = 0;
	while (buf[z] && buf[z] != '\n')
		z++;
	if (!buf[z])
		return (free(buf), NULL);
	ret = ft_calloc(ft_strlen(buf) - z + 1, sizeof(char));
	if (!ret)
		return (free(buf), NULL);
	s = 0;
	z++;
	while (buf[z])
		ret[s++] = buf[z++];
	return (free(buf), ret);
}

char	*readfunk(int fd, char *buf)
{
	int		readen;
	char	*temp;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
	{
		free(buf);
		return (0);
	}
	readen = 1;
	while (!ft_strchr(buf, '\n') && readen != 0)
	{
		readen = read(fd, temp, BUFFER_SIZE);
		if (readen < 0)
			return (free(temp), free(buf), NULL);
		temp[readen] = '\0';
		buf = ft_strjoin(buf, temp);
		if (!buf)
			return (free(temp), buf);
	}
	return (free(temp), buf);
}

char	*get_next_line(int fd, t_data *data)
{
	char		*ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	data->gnl_buffer = readfunk(fd, data->gnl_buffer);
	if (!data->gnl_buffer)
		return (NULL);
	ret = take_line(data->gnl_buffer);
	data->gnl_buffer = delete_line(data->gnl_buffer);
	return (ret);
}
/*
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	const char	*filename;
	int			fd;

	filename = "example.txt";
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening the file");
		return (1);
	}
	char *kek =get_next_line(fd);
	char *kek1 =get_next_line(fd);
	char *kek2 =get_next_line(fd);
	char *kek3 =get_next_line(fd);
	printf("%s", kek);
	printf("%s", kek1);
	printf("%s", kek2);
	printf("%s", kek3);
	free(kek);
	free(kek1);
	free(kek2);
	free(kek3);
	printf("%d", BUFFER_SIZE);
	close(fd);
	return (0);
}
*/