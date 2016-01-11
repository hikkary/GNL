/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 17:02:19 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/01/11 17:58:00 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(int argc,char **argv)
{
	int fd;
	char *line;
 	int i;
 
//	i = 0;
	fd = open(argv[1], O_RDONLY);
//	fd = 0;
//	i = 0;	
//
/*	while(get_next_line(fd, &line))
	{
		ft_putendl(line);
		//ft_putendl(line);
		free(line);
	}


 	i =	get_next_line(fd, &line);
	printf("%d", i);
	ft_putendl(line);
	free(line);

	//test 

	while(i <= 3)
	{
		get_next_line(fd, &line);
		ft_putendl(line);
		free(line);
		i++;
	}
*/
	//test final/
	while(get_next_line(fd, &line))
	{
		ft_putendl(line);
		free(line);
	}

	return (0);
}
