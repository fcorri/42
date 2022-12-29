NAME		=	get_next_line

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -D BUFFER_SIZE=0

SRCS		=	get_next_line.c get_next_line_utils.c

BONUS_SRCS	=	get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS		=	$(SRCS:.c=.o)

BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS)

RM			=	rm -fr

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
