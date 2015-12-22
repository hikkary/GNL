/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 19:28:05 by zkerkeb           #+#    #+#             */
/*   Updated: 2015/12/22 23:15:58 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int len_line(char **line)
{
	int i;

	i = 0;

	return(0);
}

char *get_line(int const fd, char *buf, char **line)
{
	int i;
	
	i = 0
	while (argv[1][i] != '\n')
	{
 		
	}
}

int get_next_line(int const fd, char **line)
{
	int i;	
	char buf[BUFF_SIZE];
	char *l;

	i =  0;	
	fd = open(argv[1], O_RDONLY);
	l = get_line(fd, buf, &argv[1]);

	return (0);
}

int main(int argc, char **argv)
{
	int fd;

		
	get_next_line(fd, &argv[1]);

	return (0);
}
