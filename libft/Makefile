NAME	=	libft.a

CC		=	cc
CFLAGS	= -Wall -Wextra -Werror

AR		=	ar
ARFLAGS	=	-rcs

RM		=	rm -rf

SRCS	=	ft_atoi.c get_strjoin.c ft_instr.c ft_isalpha.c ft_isspace.c \
			ft_isdigit.c ft_strchr.c ft_strcmp.c ft_strdup.c ft_atoi_check.c \
			ft_strjoin.c ft_strlen.c ft_strncpy.c ft_substr.c \
			ft_split.c get_next_line.c

OBJS	= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
