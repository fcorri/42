# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 18:12:28 by fcorri            #+#    #+#              #
#    Updated: 2023/09/11 14:33:39 by fcorri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	$(BUILD_DIR)/push_swap

#MIN				=	0
#MAX				=	20
#MANY			=	10
#ARGS			:=	$(shell python3 utils/generate_random_numbers.py $(MIN) $(MAX) $(MANY))
#ARGS			=	4 11 7 6 17 13 18 9 19 12
#ARGS			=	6 5 12 10 9 1 17
ARGS			=	5 2 7 1 6 3 9 4 8

CFLAGS			=	-g3
REQUIRED_CFLAGS	=	$(CFLAGS) -Wall -Wextra -Werror
CPPFLAGS		=	$(addprefix -I, $(LIBFT_DIR)/$(INC_DIR))
LDFLAGS			=	$(addprefix -L, $(LIBFT_DIR)/$(BUILD_DIR))
LDLIBS			=	$(addprefix -l, ft)

BUILD_DIR		=	build
INC_DIR			=	$(BUILD_DIR)/inc
OBJS_DIR		=	$(BUILD_DIR)/obj
LIBFT_DIR		=	../../libft
SRCS_DIR		=	src
P_HEADER		=	$(SRCS_DIR)/push_swap_p.h

SRCS			=	$(SRCS_DIR)/main.c \
					$(SRCS_DIR)/init.c \
					$(SRCS_DIR)/print.c \
					$(SRCS_DIR)/utils.c \
					$(SRCS_DIR)/stack.c \
					$(SRCS_DIR)/queue.c \
					$(SRCS_DIR)/order.c \
					$(SRCS_DIR)/swap.c \
					$(SRCS_DIR)/push.c \
					$(SRCS_DIR)/rotate.c \
					$(SRCS_DIR)/reverse.c \

OBJS			=	$(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

RM				=	rm -fr

all: $(NAME)

$(NAME): $(LIBFT_DIR)/$(BUILD_DIR)/libft.a $(OBJS)
	$(CC) $(OBJS) $(REQUIRED_CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(LIBFT_DIR)/$(BUILD_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(P_HEADER)
	@mkdir -p $(@D)
	$(CC) -c $< $(REQUIRED_CFLAGS) $(CPPFLAGS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

clear:
	clear

run: clear all
	$(CC) $(OBJS) $(REQUIRED_CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	$(NAME) $(ARGS)

check: clear all
	$(CC) -c $(SRCS_DIR)/order.c $(REQUIRED_CFLAGS) $(CPPFLAGS) -DCHECK=1 -o $(OBJS_DIR)/order.o
	$(CC) $(OBJS) $(REQUIRED_CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	$(NAME) $(ARGS)

mem: clear all
	valgrind --track-origins=yes --leak-check=full $(NAME) $(ARGS)

vgdb: clear all
	valgrind --track-origins=yes --vgdb-error=0 $(NAME) $(ARGS)

gdb: clear all
	echo "target remote | vgdb" > .gdbinit
	echo "c" >> .gdbinit
	gdb $(NAME)

debugf: clear all
	vi .gdbinit && gdb --args $(NAME) $(ARGS)

debug: clear all
	gdb --args $(NAME) $(ARGS)

debugc: clear all
	$(CC) -c $(SRCS_DIR)/order.c $(REQUIRED_CFLAGS) $(CPPFLAGS) -DCHECK=1 -o $(OBJS_DIR)/order.o
	$(CC) $(OBJS) $(REQUIRED_CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	gdb --args $(NAME) $(ARGS)

debugcf: clear all
	$(CC) -c $(SRCS_DIR)/order.c $(REQUIRED_CFLAGS) $(CPPFLAGS) -DCHECK=1 -o $(OBJS_DIR)/order.o
	$(CC) $(OBJS) $(REQUIRED_CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	vi .gdbinit && gdb --args $(NAME) $(ARGS)
