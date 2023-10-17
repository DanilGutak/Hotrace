/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:13:15 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/15 17:34:43 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char			**keys;
	char			**values;
	unsigned int	length;
	unsigned int	count;
	char			**temp1;
	char			**temp2;
	char			*gnl_buffer;
	int				res;
	char			*buffer;
}					t_data;

char	*get_next_line(int fd, t_data *data);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
