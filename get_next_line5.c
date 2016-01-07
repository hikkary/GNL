/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:44:02 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/01/07 18:22:25 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char **stock(char *buf, char **b, int fd)
{
	int ret;
	int i;
	
	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE) != 0 || i == 4200))
	{
		buf[ret] = '\0';
		b[0] = ft_strjoin(b[0], buf);
		i++;
	}
	if (ret == 0)
		b[98][1] = '0';
	return(b);
}

char **ft_write(char **line, char **b)
{
	int i;

	while (b[0][i] != '\n' && b[0][i] != '\0' && b[0][i] != EOF)
	{
		line[0][i] = b[0][i];
		i++;
	}
	return (line);
}

int get_next_line(int const fd, char **line)
{
	static char **b;
	char buf[BUFF_SIZE + 1];

	if (!b)
		b = (char **)malloc(sizeof(char *) * 100);
	if (!b[0])
		b[0] = ft_strnew(BUFF_SIZE + 1);
	if(!b[98])
		b[98] = ft_strnew(3);
	line[0] = ft_strnew(BUFF_SIZE + 1);
	// ajouter la condition
	b = stock(buf, b, fd);
	line = ft_write(line[0], b);
	b[0] = ft_strsub(b[0], ft_strlen(ligne) + 1, ft_strlen(b[0]));
	return(1)
}

