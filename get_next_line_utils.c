#include "get_next_line.h"

/*
*	Return the string length
*/

size_t	ft_strlen(const char* s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

/*
*	Return the index of the found character in the string
*/

int	ft_strchr_pos(const char* s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (i);
	return (-1);
}

/*
*	Take a string as input, allocate memory for a copy of it and copy
*/

char* ft_strdup(const char* s)
{
	size_t	i;
	char* ss;

	i = 0;
	ss = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!ss)
		return (NULL);
	while (s[i])
	{
		ss[i] = s[i];
		i++;
	}
	ss[i] = 0;
	return (ss);
}

/*
*	Take 2 strings as inputs and concatenate them in a new allocated string
*/

char* ft_strjoin(char const* s1, char const* s2)
{
	size_t	i;
	size_t	j;
	size_t	s1len;
	size_t	s2len;
	char* s;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s = (char*)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!s)
		return (NULL);
	while (i < s1len)
	{
		s[i] = s1[i];
		i++;
	}
	while (j < s2len)
		s[i++] = s2[j++];
	s[i] = 0;
	return (s);
}

/*
*	Create a allocated substring based on a string,
*	start index on this string and number of bytes to copy
*/

char* ft_substr(char const* s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	count;
	char* ss;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		count = 0;
	else if (ft_strlen(s + start) >= len)
		count = len;
	else
		count = ft_strlen(s + start);
	ss = (char*)malloc(sizeof(char) * (count + 1));
	if (!ss)
		return (NULL);
	while (i < count)
	{
		ss[i] = s[start + i];
		i++;
	}
	ss[i] = 0;
	return (ss);
}