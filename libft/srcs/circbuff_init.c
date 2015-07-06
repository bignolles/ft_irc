#include <stdlib.h>
#include "circbuff.h"

t_circbuff	*circbuff_init(void)
{
	t_circbuff	*ret;

	ret = malloc(sizeof(t_circbuff));
	ret->buff = malloc(sizeof(char) * CIRCBUFF_SIZE);
	ret->begin = CIRCBUFF_BEGIN;
	ret->end = CIRCBUFF_END;
}
