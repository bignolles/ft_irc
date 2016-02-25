CC =				clang
AR =				ar
NAME =				libcirc_buff.a
SRCS_DIR =			./srcs/
INCLUDES_DIR =		./includes/
OBJ_DIR =			./obj/
LIBFT_DIR =			../libft
LIBFT_INCLUDES =	$(LIBFT_DIR)/includes/
LIBFT_LIB =			$(LIBFT_DIR)/libft.a
SRCS =				circbuff_init.c
OBJ =				$(SRCS:.c=.o)
CFLAGS =			-Wall -Wextra -Werror -I$(INCLUDES_DIR) -c -o
LDFLAGS =			-q

all: $(LIBFT_LIB) $(OBJ_DIR) $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $@

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
