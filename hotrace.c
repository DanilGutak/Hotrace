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

char	*read_end(char **input, t_data *data)
{
	int		i;
	char	*temp;

	i = 0;
	temp = malloc(2);
	if (!temp)
	{
		temp_fail(&*input, &*temp, &*data);
		return (NULL);
	}
	if (read(0, temp, 1) == 0)
	{
		while (input[i])
		{
			free(input[i++]);
		}
		free(input);
		free(temp);
		return (NULL);
	}
	temp[1] = '\0';
	return (temp);
}

int	fill_data(t_data *data, char **input)
{
	int	i;

	while (input[data->length])
		data->length++;
	data->length += 2000000;
	i = 1;
	data->keys = ft_calloc(data->length, sizeof(char *));
	data->values = ft_calloc(data->length, sizeof(char *));
	while ((unsigned int)i < data->length - 2000000)
	{
		add(&*data, input[i - 1], input[i]);
		i += 2;
	}
	return (0);
}

int	main(void)
{
	char	**input;
	char	*s;
	char	*temp;
	char	*str;
	t_data	data;

	str = NULL;
	temp = NULL;
	s = NULL;
	data.length = 0;
	s = input_parser(s);
	if (!s)
		return (1);
	input = ft_split(s, '\n');
	free(s);
	if (!input)
		return (1);
	if (fill_data(&data, &*input))
		return (1);
	if (input_parser2(&*input, &*str, &*temp, &data))
		return (1);
	free_double_p(data.keys, data.length);
	free_double_p(data.values, data.length);
}
