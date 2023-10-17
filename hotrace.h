/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:52:45 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/15 17:55:42 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char			*ft_strjoin1(char *s1, char const *s2);
int				add2(t_data *data, char *key, char *value);
char			*ft_strdup(const char *s);

int				checkset(char c, char const *set);
char			**ft_split(char const *s, char c);
int				ft_strcmp(char *s1, char *s2);
int				free_all(t_data *data);
int				search_str(char *str);
char			*read_end(char **input, t_data *data);
int				temp_fail(char **input, char *temp, t_data *data);

int				add(t_data *data, char *key, char *value);
void			search(t_data *data, char *str);
unsigned long	hash_fnv(char *str);
void			free_double_p(char **p, unsigned int j);

#endif