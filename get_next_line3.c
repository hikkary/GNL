#include "get_next_line.h"
#include <stdio.h>

int check_buff(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return(1);
		i++;
	}
	return (0);
}
// refaire la fonction mais avec le buf


char *len_line(int fd, char *buf, char *r, char **line)
{
	int i;
	int ret;
	int j;
	int b;
	j = 0;

//	if (r)
	//	line[0] = check(line, r);
	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE) != 0 && b != 1))
	{
	//	if (check_buff(line[0]) == 0)
		//	ret = read(fd, buf, BUFF_SIZE);
			line[0] = ft_strjoin(line[0], buf);
			b = check_buff(buf);
	}
	line[0] = ft_strjoin(line[0], buf);
	while (line[0][i] != '\n' && line[0][i] != '\0')
		i++;
	while (line[0][i] != '\0')
	{
		i++;
		r[j] = line[0][i];
//		line[0][i] = ' ';
		j++;
	}
//	line[0] = ft_strtrim(line[0]);
	//printf("\n\n%s\n\n");
	line[0] = ft_strsub(line[0], 0, (i - j));
	return(line[0]);
}

char *check(char **line, char *r)
{
	int i;
	//ft_putstr("ace");
	i = 0;
	while (r[i] != '\n' && r[i] != '\0' )
	{
		line[0][i] = r[i];
		//ft_putchar(r[i]);
		r[i] = ' ';
		i++;
	//	if(r[i] == '\0')
	//		ft_strdel(&r);
	}
	//ft_strtrim(r);
	//printf("\n\n%s\n\n",r);
	return (line[0]);
}

int get_next_line(int const fd, char **line)
{
	int i;
	int ret;
	char buf[BUFF_SIZE + 1];
	static char *r;
	i =  0;
	
	line[0] = ft_strnew(BUFF_SIZE + 1); // a modifier apres
	if(!r)
		r = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (r)
		line[0] = check(line, r);
	if (r && check_buff(line[0]) == 1)
	{
		ft_putstr(line[0]);
		return(0);
	}
	line[0] = len_line(fd, buf, r, line);
	//if (line =
	ft_putstr(line[0]);
	ft_putchar('\n');
	ft_strdel(&line[0]);
	//  ft_putstr(r);
	return (0);
}

//A FAIRE creer la fonction qui colle la static r a line , et     qui si ya pas de buffer la renvoi a lautre fonction pour conti    nuer a lire, Vive la republique, vive la France

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
	free(line);
	get_next_line(fd, &line);
	free(line);
	get_next_line(fd, &line);
	free(line);
	return (0);
}
