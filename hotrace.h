
#ifndef HOTRACE_H
# define HOTRACE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char			**keys;
	char			**values;
	unsigned int	length;
}					t_data;

char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
char				**ft_split(char const *s, char c);

#endif