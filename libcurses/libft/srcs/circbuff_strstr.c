#include "circbuff.h"

int	circbuff_strstr(t_circbuff *buff, char *str)
{
	int	i;
	int	j;
	int	ret;

	i = buff->begin;

	while (i % CIRCBUFF_SIZE != buff->end)
	{
		if (buff->buff[i % CIRCBUFF_SIZE] == str[0])
		{
			j = 0;
			while (str[j] && (i + j) % CIRCBUFF_SIZE != buff->end
				&& str[j] == buff->buff[(i + j) % CIRCBUFF_SIZE])
				++j;
			if (!str[j])
				return (i);
		}
		++i;
	}
	return (-1);
}
