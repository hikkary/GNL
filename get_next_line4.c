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

int line(char *line)
{
	int i;
	
	i = 0;
	while (line[i] != '\0')
	{
			
	}	
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
	line[0][i] = '\0';
	if (r[i] == '\n')
		r[i] = 32;
	i++;	
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
	while (check_buff(r, '\n') != 1 && r)
	{
		if ((ret = read(fd, buf, BUFF_SIZE) != 0))
		{
			r = ft_strjoin(r, buf);
		}
	}
	line[0] = check(&line[0], r);
	
	r = ft_strsub(r, ft_strlen(line[0]) + 1, ft_strlen(r));;
	if (line[0])
		return(1);
	else
		return (0);
}

// Regler la putain de sa race la condition darret grace a R
int main(int argc, char **argv)
{
	int fd;
	char *line;
	int fd2;

	// line = (char *)malloc(sizeof(char ) * 1);
	fd = open(argv[1], O_RDONLY);
	//fd2 = open(argv[2], O_RDONLY);
	//while(argv[1])
	while(get_next_line(fd, &line))
	{
		ft_putendl(line);
		free(line);
	}
	return (0);
}
