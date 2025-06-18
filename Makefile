NAME		=	push_swap
CHECKER		=	checker

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3

SRCS		=	src/main.c\
				src/validation.c src/utils.c src/init_stack.c\
				src/sort_stack.c src/sort_little_stack.c src/sort_utils.c\
				src/set_index.c\
				src/push_operations.c src/swap_operations.c src/rotate_operations.c src/rr_operations.c

BSRCS		=	bonus/main_bonus.c\
				bonus/init_stack_bonus.c bonus/utils_2_bonus.c bonus/utils_bonus.c bonus/validation_bonus.c \
				bonus/push_operation_bonus.c bonus/rr_operations_bonus.c \
				bonus/rotate_operations_bonus.c bonus/swap_operations_bonus.c

OBJS		=	$(SRCS:%.c=%.o)
BOBJS		=	$(BSRCS:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJS)
	make -C ./libft
	make -C ./libft clean
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(BOBJS)
	make -C ./libft
	make -C ./libft clean
	$(CC) $(CFLAGS) $(BOBJS) ./libft/libft.a -o $(CHECKER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BOBJS)

fclean: clean
	rm -rf $(NAME) $(CHECKER) ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re bonus
