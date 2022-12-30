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
#include "get_next_line_bonus.h"

int main()
{

	int fd1 = open("test1.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);
	char *str1 = get_next_line(fd1);
	char *str2 = get_next_line(fd2);
	char *str3 = get_next_line(fd3);

	// dup2(fd3, 5000);
	
	while (str1 || str2 || str3)
	{
		printf("%s", str1);
		free(str1);
		str1 = get_next_line(fd1);
		printf("%s", str2);
		free(str2);
		str2 = get_next_line(fd2);
		printf("%s", str3);
		free(str3);
		str3 = get_next_line(fd3);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	free(str1);
	free(str2);
	free(str3);
	return (0);

}

