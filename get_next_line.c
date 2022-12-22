/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:29:38 by htam              #+#    #+#             */
/*   Updated: 2022/12/12 15:29:39 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

int	ft_nlcheck(char *s)
{
	int	n;

	n = 0;
	while (s[n])
	{
		if (s[n] == '\n' || s[n] == 0)
			return (n);
		n++;
	}
	return (-1);
}

char	*ft_readandstash(int fd, char *buff, char *stash)
{
	int read_count;

	read_count = 1;
	// if (!stash)
	// 	stash = ft_strdup("");
	// if(!buff)
	// 	buff = ft_strdup("");
	//stash = ft_strjoin(stash, buff);
	while (read_count > 0 )
	{
		read_count = read(fd, buff, BUFFER_SIZE);
		buff[read_count] = 0;
		stash = ft_strjoin(stash, buff);
		if (ft_nlcheck(buff) >= 0)
			break ;
	}
	//printf("buff = (%s)\n", buff);
	return (stash);
}

char	*ft_trimstash(char *stash)
{
	int		nlpos;
	char	*output;

	nlpos = ft_nlcheck(stash);
	output = ft_substr(stash, 0, nlpos + 1);
	return (output);
}

char	*ft_newstash(char *stash)
{
	int		stash_len;
	int		nlpos;
	char	*newstr;

	stash_len = ft_strlen(stash);
	nlpos = ft_nlcheck(stash);
	newstr = ft_substr(stash, nlpos + 1, stash_len - nlpos);
	free(stash);
	return (newstr);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	// char		*temp;
	char		*output;
	char		buff[BUFFER_SIZE + 1];

	//printf("stash = (%s)\n", stash);
	//buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	

	stash = ft_readandstash(fd, buff, stash);
	//free(buff);
	if (fd < 0 || !stash)
		return (0);
	//trim stash into output
	// temp = ft_strdup(stash);
	output = ft_trimstash(stash);
	if (ft_strlen(output) == 0)
		return (NULL);
	//remake stash for next round
	stash = ft_newstash(stash);
	return (output);
	
}

// char	*get_next_line(int fd)
// {
// 	char		*buff;
// 	int			size_read;
// 	static char	*stash;
// 	static char *temp;
// 	char		*stash2;
// 	int			n;

// 	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buff)
// 	{
// 		free(buff);
// 		return (NULL);
// 	}
// 	size_read = 1;
// 	if (!temp)
// 		temp = ft_strdup("");
// 	temp = ft_strjoin(temp, buff);
// 	stash = ft_strdup(temp);
// 	if (BUFFER_SIZE <= 0 || fd < 0)
// 		return (0);
// 	while (size_read != 0)
// 	{
// 		if (!stash)
// 			stash = ft_strdup("");
// 		size_read = read(fd, buff, BUFFER_SIZE);
// 		buff[size_read] = 0;
// 		stash = ft_strjoin(stash, buff);
// 		if (ft_nlcheck(stash) >= 0)
// 			break ;
// 	}
// 	if (ft_strlen(stash) == 0)
// 	{
// 		free(stash);
// 		stash = NULL;
// 		return (NULL);
// 	}
// 	n = ft_nlcheck(stash);
// 	temp = ft_substr(stash, n + 1, ft_strlen(stash) - n);
// 	// printf("%s\n", temp);
// 	stash = ft_substr(stash, 0, n + 1);
// 	stash2 = ft_strdup(stash);
// 	free(stash);
// 	stash = NULL;
// 	return (stash2);
// }