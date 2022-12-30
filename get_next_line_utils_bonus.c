/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:31:35 by htam              #+#    #+#             */
/*   Updated: 2022/12/29 22:29:52 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	if (!s)
		return (0);
	while (s[n])
		n++;
	return (n);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*nstr;

	i = 0;
	nstr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!nstr)
		return (NULL);
	while (s[i])
	{
		nstr[i] = s[i];
		i++;
	}
	nstr[i] = 0;
	return (nstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		n;
	unsigned int		i;
	char				*substr;

	n = 0;
	i = 0;
	substr = malloc(sizeof(*substr) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[n])
	{
		if (n >= start && i < len)
		{
			substr[i] = s[n];
			i++;
		}
		n++;
	}
	substr[i] = 0;
	if (substr[0] == 0)
	{
		free(substr);
		return (NULL);
	}
	return (substr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		n;
	int		i;
	char	*newstr;

	n = 0;
	i = 0;
	if (!s1)
		return (NULL);
	newstr = malloc(sizeof(*newstr) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	while (s1[n])
	{
		newstr[n] = s1[n];
		n++;
	}
	while (s2[i])
	{
		newstr[n + i] = s2[i];
		i++;
	}
	newstr[n + i] = 0;
	free(s1);
	return (newstr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	ch;
	int		n;

	str = (char *)s;
	ch = (char)c;
	n = 0;
	while (str[n] != ch && str[n])
		n++;
	if (str[n] == ch)
		return (str + n);
	return (NULL);
}
