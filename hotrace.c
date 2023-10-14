/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:11:14 by secker            #+#    #+#             */
/*   Updated: 2023/10/14 12:41:05 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	main(void)
{
	char	**input;
	char	*s;
	char	*temp;
	char	*str;
	int		i;

	i = 0;
	s = NULL;
	str = NULL;
	while (1)
	{
		temp = malloc(2);
		read(0, temp, 1);
		temp[1] = '\0';
		if (s)
			s = ft_strjoin(s, temp);
		else
			s = ft_strdup(temp);
		if (s[i] == '\n' && s[i - 1] == '\n')
			break ;
		free(temp);
		i++;
	}
	input = ft_split(s, '\n');
	free(s);
	i = 0;
	while (1)
	{
		temp = malloc(1);
		read(0, temp, 1);
		if (temp[0] == '\n')
			break ;
		if (str)
			str = ft_strjoin(str, temp);
		else
			str = ft_strdup(temp);
		free(temp);
	}
        printf("%s", str);
}
