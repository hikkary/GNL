/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 17:02:19 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/01/07 23:05:26 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int main(void)
{
	int fd;
	char *line;
 	int i;

	//fd = open(argv[1], O_RDONLY);
	fd = 0;
//	i = 0;	
//
/*	while(get_next_line(fd, &line))
	{
		ft_putendl(line);
		//ft_putendl(line);
		free(line);
	}
*

	get_next_line(fd, &line);
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

	//test final
*/
	while(get_next_line(fd, &line))
	{
		ft_putendl(line);
		free(line);
	}
	
}
