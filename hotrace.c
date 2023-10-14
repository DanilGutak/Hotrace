
#include "hotrace.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n--)
	{
		*temp++ = '\0';
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	check;

	check = nmemb * size;
	if (nmemb != 0 && check / nmemb != size)
		return (0);
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	res = malloc(nmemb * size);
	if (!res)
		return (0);
	ft_bzero(res, nmemb * size);
	return (res);
}
int	main(void)
{
	char	**input;
	char	*s;
	char    *temp;
	char	*str;
	int		i;
	t_data	data;

	i = 0;
	s = NULL;
	str = NULL;
    temp = NULL;
	while (1)
	{
        temp = malloc(2);
		if (read(0, temp, 1) == 0)
		{
            free(temp);
			free(s);
			return (1);
		}
        temp[1]='\0';
		if (s)
			s = ft_strjoin(s, temp);
		else
			s = ft_strdup(temp);
        free(temp);
		if (s[i] == '\n' && s[i - 1] == '\n')
			break ;
		i++;
	}
	input = ft_split(s, '\n');
	data.length = 0;
	while (input[data.length])
		data.length++;
	data.length += 2000000;
	i = 1;
	data.keys = ft_calloc(data.length, sizeof(char *));
	data.values = ft_calloc(data.length, sizeof(char *));
	while ((unsigned int)i < data.length - 2000000)
	{
		add(&data, input[i - 1], input[i]);
		i += 2;
	}
	free(s);
	i = 0;
	while (1)
	{
		temp = malloc(2);
		if (read(0, temp, 1) == 0)
		{
			while (input[i])
			{
				free(input[i++]);
			}
			free(input);
			free(temp);
			break ;
		}
		temp[1] = '\0';
		if (temp[0] == '\n')
		{
			search(&data, str);
			free(str);
			str = 0;
			free(temp);
			continue ;
		}
		if (str)
			str = ft_strjoin(str, temp);
		else
			str = ft_strdup(temp);
		free(temp);
	}
	free_double_p(data.keys, data.length);
	free_double_p(data.values, data.length);
}
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

void	search(t_data *data, char *str)
{
	unsigned int index;

	if (!str)
	{
		write(1,": Not found.\n", 13);
		return ;
	}
	index = hash_fnv(str) % data->length;
	while (index < data->length)
	{
		if (ft_strcmp(data->keys[index], str) == 0)
		{
			write(1, data->values[index], ft_strlen(data->values[index]));
			write(1,"\n", 1);
			return ;
		}
		index++;
	}
	write(1,str, ft_strlen(str));
	write(1,": Not found.\n", 13);
}
