
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
			exit(1);
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
		printf("lol not type\n");
		return ;
	}

	index = hash_fnv(str) % data->length;
	while (index < data->length)
	{
		if (ft_strcmp(data->keys[index], str) == 0)
		{
			printf("%s\n", data->values[index]);
			return ;
		}
		index++;
	}
	printf("lol not found\n");
}