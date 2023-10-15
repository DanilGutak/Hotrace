
#ifndef HOTRACE_H
# define HOTRACE_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_data
{
	char			**keys;
	char			**values;
	unsigned int	length;
	unsigned int	count;
	char			**temp1;
	char			**temp2;
	
}					t_data;

char				*ft_strjoin1(char *s1, char const *s2);
int					add2(t_data *data, char *key, char *value);
char				*ft_strdup(const char *s);
size_t				ft_strlen1(const char *s);
char				**ft_split(char const *s, char c);
int					ft_strcmp(char *s1, char *s2);
int					search_str(char *str);
char				*read_end(char **input, t_data *data);
int					temp_fail(char **input, char *temp, t_data *data);

int					add(t_data *data, char *key, char *value);
void				search(t_data *data, char *str);
unsigned int		hash_fnv(char *str);
void				free_double_p(char **p, unsigned int j);

#endif