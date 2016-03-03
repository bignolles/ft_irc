CC =				clang
NAME =				./libring_buff.a
UNIT_NAME =			tests
SRCS_DIR =			./srcs/
INCLUDES_DIR =		./includes/
OBJ_DIR =			./obj/
UNIT_DIR =			./unit_tests/
SRCS =				ringbuff_destruct.c\
					ringbuff_dump.c\
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
UNIT_SRCS =			main.c
UNIT_OBJ =			$(UNIT_SRCS:.c=.o)
CFLAGS =			-Wall -Wextra -Werror -I$(INCLUDES_DIR) -c -g -o
LDFLAGS =			-q

all: $(OBJ_DIR) $(NAME)

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

unit: $(UNIT_NAME)

$(UNIT_NAME): $(addprefix $(UNIT_DIR), $(UNIT_OBJ))
	$(CC) -L. -lring_buff $^ -o $@

$(UNIT_DIR)%.o: $(UNIT_DIR)%.c
	$(CC) -Wall -Wextra -Werror -I./includes/ -c -o $@ $<

.PHONY: all clean fclean re
