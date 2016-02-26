CC =				clang
AR =				ar
NAME =				libring_buff.a
SRCS_DIR =			./srcs/
INCLUDES_DIR =		./includes/
OBJ_DIR =			./obj/
LIBFT_DIR =			../libft
LIBFT_INCLUDES =	$(LIBFT_DIR)/includes/
LIBFT_LIB =			$(LIBFT_DIR)/libft.a
SRCS =				ringbuff_destruct.c\
					ringbuff_err_no_fatal.c\
					ringbuff_get_space.c\
					ringbuff_has_space.c\
					ringbuff_init.c\
					ringbuff_read.c\
					ringbuff_read_cpy.c\
					ringbuff_read_to_str.c\
					ringbuff_write.c\
					ringbuff_write_cpy.c
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
