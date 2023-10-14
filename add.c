#include "hotrace.h"

unsigned int	hash_fnv(char *str)
{
	unsigned int	fnv_prime;
	unsigned int	hash;
	unsigned int	i;
	unsigned int	length;

	fnv_prime = 0x811C9DC5;
	hash = 0;
	i = 0;
	length = ft_strlen(str);
	while (i < length)
	{
		hash *= fnv_prime;
		hash ^= (*str);
		i++;
	}
	return (hash);
}

int	add(t_data *data, char *key, char *value)
{
	unsigned int	index;

	index = hash_fnv(key) % data->length;
	while (index < data->length)
	{
		if (!data->keys[index])
		{
			data->keys[index] = ft_strdup(key);
			if (!data->keys[index])
				return (1);
			data->values[index] = ft_strdup(value);
			if (!data->values[index])
				return (1);
			printf("%d\n", index);
			return (0);
		}
		index++;
	}
	return (1);
}

int	main(void)
{
	t_data data;

	data.keys = malloc(21000 * sizeof(char *));
	data.values = malloc(21000 * sizeof(char *));
	data.length = 21000;
	add(&data, "kok", "ya ebu");
	add(&data, "Danil", "Gutak");
	add(&data,array[0], array[1]);
	printf("%s  %s\n", data.keys[6759], data.values[6759]);
	printf("%s  %s\n", data.keys[7404], data.values[7404]);
	printf("%s  %s\n", data.keys[9088], data.values[9088]);
}