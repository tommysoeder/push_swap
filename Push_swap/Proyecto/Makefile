NAME        := push_swap
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
INCS        := -Iinclude

SRC         := src/main.c \
               src/stack_init.c \
               src/stack_ops_basic.c \
               src/parse.c \
               src/checks.c \
			   src/small_sort.c \
       		   src/sort_radix.c \
			   src/ps_atol.c \
			   src/ops_utils.c \
			   src/ops_swap_push.c \
			   src/ops_rotate.c \
    		   src/ops_reverse_rotate.c \
			   src/split_ws.c \
			   src/run_sort.c \

OBJ         := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCS) $(OBJ) -o $(NAME)

%.o: %.c include/push_swap.h
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
