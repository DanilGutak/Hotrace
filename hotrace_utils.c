#include "hotrace.h"

size_t	ft_strlen(const char *s)
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

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (jstr);
}
