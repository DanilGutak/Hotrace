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
	return (0);
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

