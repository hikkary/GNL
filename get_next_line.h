/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:30:47 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/01/13 22:38:10 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 11000
# define DEBUG printf("%d - %s - %s\n", __LINE__, __FILE__, __func__);
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
typedef struct s_struct 
{
   	char buf[BUFF_SIZE + 1];
	char *total;
    char *an;
   	int t;
   	int stop;
}				t_g;

int get_next_line(int const fd, char **line);

#endif
