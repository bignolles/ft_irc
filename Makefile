CLI =					client
SERV =					serveur
CC =					gcc
RINGBUFF_DIR=			./ring_buff
RINGBUFF =				ring_buff
RINGBUFF_NAME =			$(RINGBUFF_DIR)/lib$(RINGBUFF).a
RINGBUFF_INCLUDES =		$(RINGBUFF_DIR)/includes
LIBCURSES_DIR =			./libcurses
LIBCURSES =				ft_ncurses
LIBCURSES_NAME =		$(LIBCURSES_DIR)/lib$(LIBCURSES).a
LIBCURSES_INCLUDES =	$(LIBCURSES_DIR)/includes
LIB =					ft
LIB_DIR =				./libft/
LIB_INCLUDES =			$(LIB_DIR)includes/
LIBFT =					$(LIB_DIR)libft.a
CFLAGS =				-Wall -Wextra -Werror -I$(LIB_INCLUDES) -g -c -o
CLI_CFLAGS =			-I./client_dir/includes -I$(RINGBUFF_INCLUDES) -I$(LIBCURSES_INCLUDES)
SERV_CFLAGS =			-I./server_dir/includes -I$(RINGBUFF_INCLUDES)
SERV_LDFLAGS =			-L$(LIB_DIR) -l$(LIB) -L$(RINGBUFF_DIR) -l$(RINGBUFF) -o
CLI_LDFLAGS =			-L$(LIB_DIR) -l$(LIB) -L$(RINGBUFF_DIR) -l$(RINGBUFF) -L$(LIBCURSES_DIR) -l$(LIBCURSES) -lncurses -o
CLI_SRC_DIR =			./client_dir/srcs/
SERV_SRC_DIR =			./server_dir/srcs/
CLI_OBJ_DIR =			./client_dir/obj/
SERV_OBJ_DIR =			./server_dir/obj/
CLI_SRCS =				main.c					create_client.c\
						read_from_client.c		write_to_serv.c\
						init_env.c				read_from_serv.c\
						check_fd.c				run_client.c\
						get_opt.c				setup_curses.c\
						usage.c					wait_for_connect.c\
						env_delete.c			read_from_serv_check.c\
						wait_read.c
SERV_SRCS =				main.c					clean_fd.c\
						disp.c					get_opt.c\
						init_env.c				run_srv.c\
						srv_accept.c			srv_create.c\
						init_fd.c				check_fd.c\
						client_write.c			client_read.c\
						get_client_input.c		handle_nick.c\
						channels.c				handle_join.c\
						handle_who.c			handle_msg.c\
						handle_channels.c		handle_help.c\
						handle_find.c			handle_where.c\
						wait_write.c			wait_read.c\
						end_connection.c
CLI_OBJ =				$(CLI_SRCS:.c=.o)
SERV_OBJ =				$(SERV_SRCS:.c=.o)

all: $(LIBFT) $(LIBCURSES_NAME) $(RINGBUFF_NAME) $(CLI) $(SERV)

$(LIBFT):
	make -C $(LIB_DIR)

$(LIBCURSES_NAME):
	make -C $(LIBCURSES_DIR)

$(RINGBUFF_NAME):
	make -C $(RINGBUFF_DIR)

$(CLI_OBJ_DIR):
	mkdir $@

$(SERV_OBJ_DIR):
	mkdir $@

$(CLI): $(CLI_OBJ_DIR) $(addprefix $(CLI_OBJ_DIR), $(CLI_OBJ))
	$(CC) $(addprefix $(CLI_OBJ_DIR), $(CLI_OBJ)) $(CLI_LDFLAGS) $(CLI)

$(CLI_OBJ_DIR)%.o: $(CLI_SRC_DIR)%.c
	$(CC) $(CLI_CFLAGS) $(CFLAGS) $@ $<

$(SERV): $(SERV_OBJ_DIR) $(addprefix $(SERV_OBJ_DIR), $(SERV_OBJ))
	$(CC) $(addprefix $(SERV_OBJ_DIR), $(SERV_OBJ)) $(SERV_LDFLAGS) $(SERV)

$(SERV_OBJ_DIR)%.o: $(SERV_SRC_DIR)%.c
	$(CC) $(SERV_CFLAGS) $(CFLAGS) $@ $<

clean: client_clean server_clean

fclean: client_fclean server_fclean

client_clean:
	rm -rf $(CLI_OBJ_DIR)

server_clean:
	rm -rf $(SERV_OBJ_DIR)

client_fclean: client_clean
	rm -f $(CLI)

server_fclean: server_clean
	rm -f $(SERV)

re: fclean all

client_re: client_fclean $(CLI)

server_re: server_fclean $(SERV)

libclean:
	make -C $(LIB_DIR) clean

libfclean:
	make -C $(LIB_DIR) fclean

.PHONY: all clean fclean libre client_clean server_clean client_fclean\
	server_fclean client_re server_re client_build server_build libclean libfclean
