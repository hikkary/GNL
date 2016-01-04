#include "get_next_line.h"
#include <stdio.h>

int check_buff(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return(1);
		i++;
	}
	return (0);
}

char *len_line(int fd, char *buf, char *r)
{
	int ret;
	if ((ret = read(fd, buf, BUFF_SIZE) != 0))
	{
			r = ft_strjoin(r, buf);
	}
	return(r);
}

char *check(char **line, char *r)
{
	int i;

	i = 0;
	while (r[i] != '\n' && r[i] != '\0' )
	{
		line[0][i] = r[i];
		r[i] = ' ';
		i++;
	}
	ft_strtrim(r);
	return (line[0]);
}

int get_next_line(int const fd, char **line)
{
	int i;
	int ret;
	char buf[BUFF_SIZE + 1];
	static char *r;
	i =  0;

	line[0] = ft_strnew(BUFF_SIZE + 1); 
	if (!r)
		r = ft_strnew(BUFF_SIZE + 1);
	while (check_buff(r) != 1)
	{
		r = len_line(fd, buf, r);
	}
	line[0] = check(line[0], r);

	return (0);
}


int main(int argc, char **argv)
{
	int fd;
	char *line;
	int fd2;

	// line = (char *)malloc(sizeof(char ) * 1);
	fd = open(argv[1], O_RDONLY);
	//fd2 = open(argv[2], O_RDONLY);
	//while(argv[1])

	get_next_line(fd, &line);
	ft_putendl(line);
	free(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	free(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	free(line);
	return (0);
}
