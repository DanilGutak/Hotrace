/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:53:32 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/15 17:54:06 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		j;
	char	*res;
	char	*buf;

	i = -1;
	buf = s1;
	while (checkset(*s1, set) == 1)
		s1++;
	j = ft_strlen(s1) - 1;
	while (j >= 0 && checkset(s1[j], set) == 1)
		j--;
	res = malloc(sizeof(char) * (j + 2));
	if (!res)
	{
		free(buf);
		return (0);
	}
	while (++i > -1 && j-- >= 0)
		res[i] = s1[i];
	res[i] = '\0';
	free(buf);
	return (res);
}

int	add_cycle(t_data *data)
{
	char	*temp1;
	char	*temp2;

	temp1 = get_next_line(0, data);
	if (!temp1)
		return (1);
	if (temp1[0] == '\n')
		return (free(temp1), 2);
	temp1 = ft_strtrim(temp1, "\n");
	if (!temp1)
		return (1);
	temp2 = get_next_line(0, data);
	if (!temp2)
		return (free(temp1), 1);
	if (temp2[0] == '\n')
		return (free(temp1), free(temp2), 2);
	temp2 = ft_strtrim(temp2, "\n");
	if (!temp2)
		return (free(temp1), 1);
	if (add(data, temp1, temp2) == 1)
		return (free(temp1), free(temp2), 1);
	free(temp1);
	free(temp2);
	return (0);
}

int	realloc_rehash(t_data *data)
{
	unsigned int	i;

	i = 0;
	data->temp1 = ft_calloc(data->length + 2000000, sizeof(char *));
	if (!data->temp1)
		return (1);
	data->temp2 = ft_calloc(data->length + 2000000, sizeof(char *));
	if (!data->temp2)
		return (free(data->temp1), 1);
	data->length += 2000000;
	while (i < data->length - 2000000)
	{
		if (data->keys[i] != 0 && add2(data, data->keys[i],
				data->values[i]) == 1)
			return (free_all(data));
	}
	free_double_p(data->temp1, data->length);
	free_double_p(data->temp2, data->length);
	data->length += 2000000;
	return (0);
}

int	data_init(t_data *data)
{
	data->length = 2000000;
	data->count = 0;
	data->keys = 0;
	data->values = 0;
	data->temp1 = NULL;
	data->temp2 = NULL;
	data->gnl_buffer = NULL;
	data->keys = ft_calloc(data->length, sizeof(char *));
	data->values = ft_calloc(data->length, sizeof(char *));
	if (!data->keys || !data->values)
		return (free_all(data));
	return (0);
}

int	main(void)
{
	t_data	data;

	if (data_init(&data) == 1)
		return (1);
	while (1)
	{
		data.res = add_cycle(&data);
		if (data.res == 2)
			break ;
		if (data.res == 1 || ((data.count > data.length / 2)
				&& realloc_rehash(&data) == 1))
			return (free_all(&data));
	}
	while (1)
	{
		data.buffer = get_next_line(0, &data);
		if (!data.buffer)
			return (free_all(&data));
		data.buffer = ft_strtrim(data.buffer, "\n");
		if (!data.buffer)
			return (free_all(&data));
		search(&data, data.buffer);
		if (data.buffer)
			free(data.buffer);
	}
}
