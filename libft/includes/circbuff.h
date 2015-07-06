#ifndef CIRCBUFF_H
# define CIRCBUFF_H

# define CIRCBUFF_SIZE		2048
# define CIRCBUFF_BEGIN		0
# define CIRCBUFF_END		0
# define CIRCBUFF_NOK		-1

typedef struct	s_circbuff
{
	char	*buff;
	int	begin;
	int	end;
}		t_circbuff;

t_circbuff	*circbuff_init(void);
char		*circbuff_retrieve(t_circbuff *buff, char *delim);
int		circbuff_add(t_circbuff *buff, char *input);
int		circbuff_strstr(t_circbuff *buff, char *delim);

#endif
