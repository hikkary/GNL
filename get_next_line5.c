/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:44:02 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/01/09 20:52:46 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int check_buff(char *buf, int cara)
{
	int i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == cara)
			return(1);
		i++;
	}
	return (0);
}

char *stock(char *buf, char **b, int fd)
{
	int ret;
	int i;

	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		b[0] = ft_strjoin(b[0], buf);
	//	i++;
	//	ft_putnbr(i);
	//	ft_putchar('\n');
		if (fd == 0 && check_buff(b[0], '\n'))
		{
			b[98][1] = '0';
			return(b[0]);
		}
//		if ((check_buff(b[0],'\n') == 1 || check_buff(b[0], EOF) == 1))
//			b[98][2] = '1';
	}
//	ft_putstr(b[0]);:w
//	ft_putstr(b[0]);
	//ft_putchar(b[98][2]);
	if (ret == 0)
		b[98][1] = '0';
	return(b[0]);
}

char **ft_write(char **line, char **b)
{
	int i;
	
	i = 0;
	//ft_putstr("ligne");
	while (b[0][i] != '\n' && b[0][i] && b[0][i] != EOF)
	{
		line[0][i] = b[0][i];
		i++;
	}
	line[0][i] = '\0';
	return (line);
}

int get_next_line(int const fd, char **line)
{
	static char **b;
	char buf[BUFF_SIZE + 1];

	if (!b)
	{
		b = (char **)malloc(sizeof(char *) * 100);
		b[0] = ft_strnew(BUFF_SIZE + 1);
		b[98] = ft_strnew(3);
	}
	//if (fd == 0)
	line[0] = ft_strnew(10000);
	while ((b[98][1] != '0'))// && (b[98][2] != '1'))
		b[0] = stock(buf, b, fd);;
	line = ft_write(line, b);
//	ft_putstr(line[0]);
//	printf("\nb avant la transformation : %s\n", b[0]);
	if (fd != 0)
		b[0] = ft_strsub(b[0], ft_strlen(line[0]) + 1, ft_strlen(b[0]));
	else
		b[0] = ft_strnew(BUFF_SIZE + 1);
	//	printf("\nb apres la transformation : %s\n", b[0]);
	if (b[98][0] == '0') //&& fd != 0)
		line[0] = NULL;
	if (b[0][0] == '\0' && b[98][1] == '0')
		b[98][0] = '0';	
	if (line[0])// || fd == 0)
		return(1);
	else
		return(0);
}

