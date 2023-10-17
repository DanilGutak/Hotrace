/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:53:09 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/15 17:21:14 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (-1);
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	free_all(t_data *data)
{
	free_double_p(data->keys, data->length);
	free_double_p(data->values, data->length);
	free_double_p(data->temp1, data->length);
	free_double_p(data->temp2, data->length);
	if (data->gnl_buffer)
		free(data->gnl_buffer);
	return (1);
}

void	free_double_p(char **p, unsigned int j)
{
	int	i;

	i = 0;
	if (p)
	{
		while ((unsigned int)i < j)
		{
			if (p[i])
				free(p[i]);
			i++;
		}
		free(p);
	}
}

int	checkset(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	while (k <= i)
	{
		str[k] = s[k];
		k++;
	}
	return (str);
}
