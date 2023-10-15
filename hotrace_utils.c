#include "hotrace.h"

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

void	free_double_p(char **p, unsigned int j)
{
	int	i;

	i = 0;
	if (p)
	{
		while ((unsigned int)i < j)
		{
			if (p[i])
				free(p[i]);
			i++;
		}
		free(p);
	}
}

size_t	ft_strlen1(const char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	while (k <= i)
	{
		str[k] = s[k];
		k++;
	}
	return (str);
}

char	*ft_strjoin1(char *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*jstr;
	int		i;
	int		j;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	j = 0;
	if (!str1)
		return (str2);
	if (!str2)
		return (str1);
	jstr = malloc((ft_strlen(str1) + ft_strlen(str2)) + 1);
	if (!jstr)
		return (jstr);
	while (str1[i])
		jstr[j++] = str1[i++];
	i = 0;
	while (str2[i])
		jstr[j++] = str2[i++];
	jstr[j] = '\0';
	free(str1);
	return (jstr);
}
