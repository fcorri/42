# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 18:12:28 by fcorri            #+#    #+#              #
#    Updated: 2023/10/04 17:01:18 by fcorri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	$(BUILD_DIR)/push_swap
CHECKER			=	$(BUILD_DIR)/checker_linux

MANY			=	500
ARGS			:=	$(shell python3 utils/generate_random_numbers.py $(MANY))

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

SRCS			=	$(SRCS_DIR)/free.c \
					$(SRCS_DIR)/init.c \
					$(SRCS_DIR)/main.c \
					$(SRCS_DIR)/min_ops.c \
					$(SRCS_DIR)/order.c \
					$(SRCS_DIR)/push.c \
					$(SRCS_DIR)/reverse.c \
					$(SRCS_DIR)/rotate.c \
					$(SRCS_DIR)/stack.c \
					$(SRCS_DIR)/swap.c \
					$(SRCS_DIR)/utils.c

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
	$(NAME) $(ARGS)
	
mem: clear all
	valgrind --tool=memcheck --track-origins=yes --leak-check=full $(NAME) $(ARGS) | $(CHECKER) $(ARGS)

vgdb: clear all
	valgrind --track-origins=yes --vgdb-error=0 $(NAME) $(ARGS)

gdb: clear all
	echo "target remote | vgdb" > .gdbinit
	echo "c" >> .gdbinit
	gdb $(NAME)

debug: clear all
	gdb --args $(NAME) $(ARGS)

debugf: clear all
	vi .gdbinit && gdb --args $(NAME) $(ARGS)

checker: clear all
	$(NAME) $(ARGS) > commands ; cat commands | $(CHECKER) $(ARGS)
	wc -l commands
	rm commands

# testa un input con n numeri casuali
define test =
	n=500
	echo $(python3 utils/generate_random_numbers.py $n) > input
	./build/push_swap $(cat input) > commands ; cat commands | ./build/checker_linux $(cat input)
	wc -l commands
	rm commands
	rm input
endef

test: clear all
	$(value test)

.ONESHELL:
