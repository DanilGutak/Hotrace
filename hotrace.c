#include "hotrace.h"

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

static int	checkset(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char  *s1, char *set)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (checkset(*s1, set) == 1)
		s1++;
	j = ft_strlen(s1) - 1;
	while (j >= 0 && checkset(s1[j], set) == 1)
		j--;
	res = malloc(sizeof(char) * (j + 2));
	if (!res)
	{
		free(s1);
		return (0);
	}
	while (j-- >= 0)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	free(s1);
	return (res);
}

int add_cycle(t_data *data)
{
	char	*temp1;
	char	*temp2;

	temp1 = get_next_line(0);
	if (!temp1)
		return (1);
	if ( temp1[0] == '\n')
		return(free(temp1), 2);
	temp1 = ft_strtrim(temp1, "\n");
	temp2 = get_next_line(0);
	if (!temp2)
		return (free(temp1), 1);
	if ( temp2[0] == '\n')
	{
		free(temp1);
		free(temp2);
		return(2);
	}
	temp2 = ft_strtrim(temp2, "\n");
	if (add(data, temp1, temp2) == 1)
		return (free(temp1),free(temp2),1);
	free(temp1);
	free(temp2);
	return (0);
}
int realloc_rehash(t_data *data)
{
	unsigned int i;

	i = 0;
	data->length += 2000000;
	data->temp1 = ft_calloc(data->length, sizeof(char *));
	if (!data->temp1)
		return (1);
	data->temp2 = ft_calloc(data->length, sizeof(char *));
	if (!data->temp2)
		return (1);
	while (i < data->length - 2000000)
	{
		if (data->keys[i] != 0 && add2(data, data->keys[i], data->values[i]) == 1)
			return (1);
	}
	return (0);
}
int	main(void)
{
	int res;
	char *temp1;
	t_data	data;

	data.length = 2000000;
	data.count = 0;
	data.keys = ft_calloc(data.length, sizeof(char *));
	data.values = ft_calloc(data.length, sizeof(char *));
	while (1)
	{
		res = add_cycle(&data);
		if (res == 2)
			break ;
		if (res == 1)
			return (1);
		if (data.count > (data.length  - data.length / 4) && realloc_rehash(&data) == 1)
			return (1);
	}
	while (1)
	{
		temp1 = get_next_line(0);
		if (!temp1)
			break ;
		if ( temp1[0] == '\n')
		{
			search(&data, "");
			free(temp1);
			continue ;
		}
		temp1 = ft_strtrim(temp1, "\n");
		search(&data, temp1);
		free(temp1);
	}
	free_double_p(data.keys, data.length);
	free_double_p(data.values, data.length);
}
