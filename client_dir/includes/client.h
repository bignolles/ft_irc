/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/22 19:05:49 by marene            #+#    #+#             */
/*   Updated: 2016/03/18 14:33:27 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/select.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include "ringbuff.h"
# include "libcurses.h"

# define CLI_OK			1
# define CLI_FAIL		0
# define CLI_ERROR		-1
# define USAGE_MSG		" <host name> <port number>"
# define BUF_SIZE		1024
# define NOFLAGS		0
# define FD_FREE		0
# define FD_SERV		1
# define FD_IO			2
# define CONNECT_CMD	"/connect"
# define PROMPT			"\n?>"
# define IRC_END		"\n\r"

# define BOX_CHAN_NAME	"top"
# define BOX_CHAT		"middle"
# define BOX_INPUT		"bottom"

# define BOLD(s) ("\033[1m" s "\033[0m")
# define UP_AND_ERASE	"\e[A\e[2K"

typedef struct				s_env
{
	int					port;
	in_addr_t			s_addr;
	int					s_sock;
	fd_set				fd_read;
	fd_set				fd_write;
	t_ringbuff			*buf_write;
	t_ringbuff			*buf_read;
	void				(*fct_read)(struct s_env*);
	void				(*fct_write)(struct s_env*);
	void				(*fct_input)(struct s_env*);
	void				(*fct_output)(struct s_env*);
	char				user_input[RINGBUFF_BUFF_SIZE + 1];
	int					cursor;
	t_screen			*screen;
}							t_env;

typedef struct sockaddr		t_sockaddr;

void						usage(char *exname);
void						get_opt(t_env *env, char *hostname, char *port);
void						init_fd(t_env *env);
void						create_client(t_env *env);
void						read_from_client(t_env *env);
void						read_from_serv(t_env *env);
void						wait_read(t_env *env);
void						write_to_serv(t_env *env);
void						init_env(t_env *env);
void						env_delete(t_env *env);
void						run_client(t_env *env);
void						check_fd(t_env *env);
void						wait_for_connect(t_env *env);
void						read_from_serv_check(t_env *env);
void						setup_curses(t_env *env);

#endif
