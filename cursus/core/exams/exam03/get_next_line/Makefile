# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <fcorri@student.42firenze.it>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 10:28:08 by fcorri            #+#    #+#              #
#    Updated: 2024/02/05 10:51:10 by fcorri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	$(BUILD_DIR)/get_next_line
ARGS			=	


CFLAGS			=	-g
REQUIRED_CFLAGS	=	$(CFLAGS) -Wall -Wextra -Werror

BUILD_DIR		=	build
OBJS_DIR		=	$(BUILD_DIR)/obj
SRCS_DIR		=	src

SRCS			=	$(SRCS_DIR)/get_next_line.c \
#					$(SRCS_DIR)/ \
#					$(SRCS_DIR)/

OBJS			=	$(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

RM				=	rm -fr

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(REQUIRED_CFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $< $(REQUIRED_CFLAGS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all
	clear ; $(NAME) $(ARGS)

mem: all
	clear ; valgrind --track-origins=yes $(NAME) $(ARGS)

debug: all
	clear ; vi .gdbinit && gdb --args $(NAME) $(ARGS)
