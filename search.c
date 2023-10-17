/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:00:58 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/15 17:18:36 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	search2(t_data *data, char *str, unsigned int index)
{
	while (index >= 0 && data->keys[index] != 0)
	{
		if (ft_strcmp(data->keys[index], str) == 0)
		{
			write(1, data->values[index], ft_strlen(data->values[index]));
			write(1, "\n", 1);
			return ;
		}
		index--;
	}
	write(1, str, ft_strlen(str));
	write(1, ": Not found.\n", 13);
}

void	search(t_data *data, char *str)
{
	unsigned int	index;
	unsigned int	i;

	if (!str)
	{
		write(1, ": Not found.\n", 13);
		return ;
	}
	i = hash_fnv(str) % data->length;
	index = i;
	while (index < data->length && data->keys[index] != 0)
	{
		if (ft_strcmp(data->keys[index], str) == 0)
		{
			write(1, data->values[index], ft_strlen(data->values[index]));
			write(1, "\n", 1);
			return ;
		}
		index++;
	}
	index = i;
	search2(data, str, i);
}
