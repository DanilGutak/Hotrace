/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:33:30 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/14 12:49:23 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	if (!str)
		return (0);
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}
unsigned int	hash_fnv(char *str)
{
	unsigned int	fnv_prime;
	unsigned int	hash;
	unsigned int	i;
	unsigned int	length;

	fnv_prime = 0x811C9DC5;
	hash = 0;
	i = 0;
	length = ft_strlen(str);
	while (i < length)
	{
		hash *= fnv_prime;
		hash ^= (*str);
		i++;
	}
	return (hash);
}
char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		size;

	size = 0;
	if (!src)
		return (NULL);
	while (src[size])
		++size;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	add(t_data *data, char *key, char *value)
{
	unsigned int	index;

	index = hash_fnv(key) % data->length;
	while (index < data->length)
	{
		if (!data->keys[index])
		{
			data->keys[index] = ft_strdup(key);
			if (!data->keys[index])
				return (1);
			data->values[index] = ft_strdup(value);
			if (!data->values[index])
				return (1);
			printf("%d\n", index);
			return (0);
		}
		index++;
	}
	return (1);
}

int	main(void)
{
	t_data data;

	data.keys = malloc(21000 * sizeof(char *));
	data.values = malloc(21000 * sizeof(char *));
	data.length = 21000;
	add(&data, "kok", "ya ebu");
	add(&data, "Danil", "Gutak");
	add(&data,array[0], array[1]);
	printf("%s  %s\n", data.keys[6759], data.values[6759]);
	printf("%s  %s\n", data.keys[7404], data.values[7404]);
	printf("%s  %s\n", data.keys[9088], data.values[9088]);
}