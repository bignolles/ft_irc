#include "circbuff.h"
#include "libft.h"

char	*circbuff_retrieve(t_circbuff *buff, char *delim)
{
	int	ret_len;
	int	end;
	char	*ret_buff;

	if (delim != NULL)
	{
		end = circbuff_strstr(buff, delim);
		ret_len = circbuff_strlen();

	}
}
