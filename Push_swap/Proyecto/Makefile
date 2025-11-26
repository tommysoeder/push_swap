NAME        := push_swap
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
INCS        := -Iinclude

SRC         := src/main.c \
               src/stack_init.c \
               src/stack_ops_basic.c \
               src/parse.c \
               src/checks.c \
			   src/ops_printed.c \
			   src/small_sort.c \
       		   src/sort_radix.c \

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
