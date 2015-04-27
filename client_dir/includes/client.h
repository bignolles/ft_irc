/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/22 19:05:49 by marene            #+#    #+#             */
/*   Updated: 2014/11/02 19:11:17 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/select.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <sys/socket.h>

# define CLI_OK			1
# define CLI_FAIL		0
# define CLI_ERROR		-1
# define USAGE_MSG		" <host name> <port number>"
# define BUF_SIZE		1024
# define NOFLAGS		0
# define FD_FREE		0
# define FD_SERV		1
# define FD_IO			2

# define BOLD(s) ("\033[1m" s "\033[0m")

typedef struct				s_fd
{
	int			type;
	void		(*fct_read)();
	void		(*fct_write)();
	char		*buf_read;
	char		*buf_write;
}							t_fd;

typedef struct				s_env
{
	int			port;
	in_addr_t	s_addr;
	int			s_sock;
	fd_set		fd_read;
	fd_set		fd_write;
	char		*buf_read;
	char		*buf_write;
}							t_env;

typedef struct sockaddr		t_sockaddr;

void						usage(char *exname);
void						get_opt(t_env *env, int argc, char **argv);
void						init_fd(t_env *env);
void						create_client(t_env *env);
void						read_from_client(t_env *env);
void						read_from_serv(t_env *env);
void						write_to_serv(t_env *env);
void						init_env(t_env *env);
void						run_client(t_env *env);
void						check_fd(t_env *env);

#endif
