
#ifndef HOTRACE_H
# define HOTRACE_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data
{
	char			**keys;
	char			**values;
	unsigned int	length;
}					t_data;

char				*ft_strjoin(char *s1, char const *s2);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
char				**ft_split(char const *s, char c);
int					ft_strcmp(char *s1, char *s2);
char				*input_parser(char *s);
int					input_parser2(char **input, char *str, char *temp,
						t_data *data);
int					read_end(char **input, char *temp);

int					add(t_data *data, char *key, char *value);
void				search(t_data *data, char *str);
unsigned int		hash_fnv(char *str);
void				free_double_p(char **p, unsigned int j);

#endif