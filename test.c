/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:57:56 by htam              #+#    #+#             */
/*   Updated: 2022/12/14 12:57:57 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"

int main()
{

	int fd = open("doc.txt", O_RDONLY);
	// int fd2 = open("test2.txt", O_RDONLY);
	// int fd3 = open("test3.txt", O_RDONLY);
	char *str = get_next_line(fd);
	// char *str2 = get_next_line(fd2);
	// char *str3 = get_next_line(fd3);
	// printf("%s", str);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
		// printf("%s", str2);
		// str2 = get_next_line(fd2);
		// printf("%s", str3);
		// str3 = get_next_line(fd3);
	}
	close(fd);
	free(str);
	return (0);

}

