#include "hotrace.h"

int	str_fail(char **input, char *temp, t_data *data)
{
	int	i;

	i = 0;
	free_double_p(data->keys, data->length);
	free_double_p(data->values, data->length);
	while (input[i])
	{
		free(input[i++]);
	}
	free(input);
	free(temp);
	return (1);
}

int	temp_fail(char **input, char *temp, t_data *data)
{
	int	i;

	i = 0;
	free_double_p(data->keys, data->length);
	free_double_p(data->values, data->length);
	while (input[i])
	{
		free(input[i++]);
	}
	free(input);
	free(temp);
	return (1);
}

char	*create_s(char *s, char *temp)
{
	char	*str;

	if (s)
		str = ft_strjoin(s, temp);
	else
		str = ft_strdup(temp);
	if (!str)
	{
		free(temp);
		return (0);
	}
	return (str);
}

char	*input_parser(char *s)
{
	char	*temp;
	int		i;

	i = 0;
	while (1)
	{
		temp = malloc(2);
		if (!temp)
			return (0);
		if (read(0, temp, 1) == 0)
		{
			free(temp);
			free(s);
			return (0);
		}
		temp[1] = '\0';
		s = create_s(s, temp);
		if (!s)
			return (0);
		free(temp);
		if (s[i] == '\n' && s[i - 1] == '\n')
			break ;
		i++;
	}
	return (s);
}

int	input_parser2(char **input, char *str, char *temp, t_data *data)
{
	while (1)
	{
		temp = malloc(2);
		if (!temp)
			return (temp_fail(&*input, &*temp, &*data));
		if (read_end(&*input, &*temp))
			break ;
		if (temp[0] == '\n')
		{
			search(&*data, str);
			free(str);
			str = 0;
			free(temp);
			continue ;
		}
		if (str)
			str = ft_strjoin(str, temp);
		else
			str = ft_strdup(temp);
		if (!str)
			return (str_fail(&*input, &*temp, &*data));
		free(temp);
	}
	return (0);
}
