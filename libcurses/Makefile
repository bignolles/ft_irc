CC =					clang
AR =					ar
NAME =					libft_ncurses.a
LIBFT_DIR =				./libft
LIBFT_INCLUDES_DIR =	$(LIBFT_DIR)/includes
LIBFT = 				$(LIBFT_DIR)/libft.a
LIBFT_NAME =			ft
SRCS_DIR =				./srcs/
INCLUDES_DIR =			./includes/
OBJ_DIR =				./obj/
SRCS =					libcurses_add_input.c\
						libcurses_add_pane.c\
						libcurses_check_input.c\
						libcurses_create_pane.c\
						libcurses_destruct_pane.c\
						libcurses_destruct_screen.c\
						libcurses_get_pane.c\
						libcurses_init.c\
						libcurses_input_char.c\
						libcurses_refresh_panes.c\
						libcurses_set_pos.c
OBJ =					$(SRCS:.c=.o)
CFLAGS =				-Wall -Wextra -Werror -I$(INCLUDES_DIR) -I$(LIBFT_INCLUDES_DIR) -g -c -o
LDFLAGS =				-q

all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(OBJ_DIR):
	mkdir -p $@

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(NAME): $(addprefix $(OBJ_DIR), $(OBJ))
	$(AR) $(LDFLAGS) $@ $^

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $@ $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
