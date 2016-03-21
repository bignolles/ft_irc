/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringbuff.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:24:50 by marene            #+#    #+#             */
/*   Updated: 2016/03/21 16:34:33 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RINGBUFF_H
# define RINGBUFF_H

# define RING_OK				0
# define RING_NOK				-1

# define RINGBUFF_BUFF_SIZE		4096
# define RINGBUFF_CHUNK_SIZE	1024

# define RINGBUFF_GREEN			"\e[33m"
# define RINGBUFF_DEFAULT		"\e[39m"

typedef enum		e_ringerr
{
	NO_ERROR,
	INVALID_START,
	FATAL_ERROR,
}					t_ringerr;

typedef struct		s_ringbuff
{
	char		*buff;
	int			start;
	int			end;
	int			len;
	t_ringerr	errno;
}					t_ringbuff;

typedef int (*t_cmp_fct)(int, t_ringbuff *buff);

int					ringbuff_err_not_fatal(t_ringerr errno);
t_ringbuff			*ringbuff_construct(void);
void				ringbuff_destruct(t_ringbuff **buff);
int					ringbuff_write(t_ringbuff *buff, char *chunk, int len);
int					ringbuff_read(t_ringbuff *buff, char *chunk, int len);
int					ringbuff_has_space(t_ringbuff *buff, int len);
int					ringbuff_write_cpy(t_ringbuff *buff, char *chunk, int len);
int					ringbuff_read_cpy(t_ringbuff *buff, char *chunk, int len);
int					ringbuff_get_read_space(t_ringbuff *buff);
int					ringbuff_get_write_space(t_ringbuff *buff);
int					ringbuff_read_to_str(t_ringbuff *buff, char **tmp, char *str);
void				ringbuff_dump(t_ringbuff *buff);
void				ringbuff_pop_last(t_ringbuff *buff);
void				ringbuff_pop_first(t_ringbuff *buff);

#endif
