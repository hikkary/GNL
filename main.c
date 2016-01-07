/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 17:02:19 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/01/07 17:03:39 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char **argv)
{
	int fd;
	char *line;

	fd = open(argv[0], O_RDONLY)
	while(get_next_line(fd, &line))
	{
		ft_putendl(line);
		free(line);
	}
}
