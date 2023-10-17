/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:53:19 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/15 19:01:59 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

unsigned long	hash_fnv(char *str)
{
	unsigned long	hash;

	hash = 5381;
	while (*str)
	{
		hash = ((hash << 5) + hash) + (*str);
		str++;
	}
	return (hash);
}

int	add_add(t_data *data, char *key, char *value, unsigned int index)
{
	while (index > 0)
	{
		if (!data->keys[index] || ft_strcmp(data->keys[index], key) == 0)
		{
			if (data->keys[index])
			{
				free(data->keys[index]);
				free(data->values[index]);
			}
			data->keys[index] = ft_strdup(key);
			if (!data->keys[index])
				return (1);
			data->values[index] = ft_strdup(value);
			if (!data->values[index])
				return (1);
			return (0);
		}
		index--;
	}
	return (1);
}

int	add(t_data *data, char *key, char *value)
{
	unsigned int	index;
	unsigned int	i;

	i = hash_fnv(key) % data->length;
	index = i - 1;
	while (++index < data->length)
	{
		if (!data->keys[index] || ft_strcmp(data->keys[index], key) == 0)
		{
			if (data->keys[index])
			{
				free(data->keys[index]);
				free(data->values[index]);
			}
			data->keys[index] = ft_strdup(key);
			if (!data->keys[index])
				return (1);
			data->values[index] = ft_strdup(value);
			if (!data->values[index])
				return (1);
			return (0);
		}
	}
	return (add_add(data, key, value, i));
}

int	add_add2(t_data *data, char *key, char *value, unsigned int index)
{
	while (index > 0)
	{
		if (!data->keys[index] || ft_strcmp(data->keys[index], key) == 0)
		{
			if (data->keys[index])
			{
				free(data->keys[index]);
				free(data->values[index]);
			}
			data->keys[index] = ft_strdup(key);
			if (!data->keys[index])
				return (1);
			data->values[index] = ft_strdup(value);
			if (!data->values[index])
				return (1);
			return (0);
		}
		index--;
	}
	return (1);
}

int	add2(t_data *data, char *key, char *value)
{
	unsigned int	index;
	unsigned int	i;

	i = hash_fnv(key) % data->length;
	index = i;
	while (index < data->length)
	{
		if (!data->temp1[index] || ft_strcmp(data->temp1[index], key) == 0)
		{
			if (data->temp1[index])
			{
				free(data->temp1[index]);
				free(data->temp2[index]);
			}
			data->temp1[index] = ft_strdup(key);
			if (!data->temp1[index])
				return (1);
			data->temp2[index] = ft_strdup(value);
			if (!data->temp2[index])
				return (1);
			return (0);
		}
		index++;
	}
	return (add_add2(data, key, value, i));
}
