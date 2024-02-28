# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 15:31:49 by fcorri            #+#    #+#              #
#    Updated: 2024/02/28 17:06:08 by fcorri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	$(BUILD_DIR)/philo
ARGS			=	4 410 200 200

VALGRIND-TOOL	=	helgrind
VALGRIND-OPTIONS=	

#CFLAGS			=	-fsanitize=thread -g3 -pthread
CFLAGS			=	-g3 -pthread
REQUIRED_CFLAGS	=	$(CFLAGS) -Wall -Wextra -Werror

BUILD_DIR		=	build
OBJS_DIR		=	$(BUILD_DIR)/obj
SRCS_DIR		=	src
P_HEADER		=	$(SRCS_DIR)/philo_p.h

SRCS			=	$(SRCS_DIR)/checker.c \
					$(SRCS_DIR)/free.c \
					$(SRCS_DIR)/init.c \
					$(SRCS_DIR)/queue.c \
					$(SRCS_DIR)/lock.c \
					$(SRCS_DIR)/logger.c \
					$(SRCS_DIR)/main.c \
					$(SRCS_DIR)/simposio.c \
					$(SRCS_DIR)/forks.c \
					$(SRCS_DIR)/utils.c

OBJS			=	$(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

RM				=	rm -fr

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(REQUIRED_CFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(P_HEADER)
	@mkdir -p $(@D)
	$(CC) -c $< $(REQUIRED_CFLAGS) -o $@

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
	valgrind --tool=$(VALGRIND-TOOL) $(VALGRIND-OPTIONS) $(NAME) $(ARGS)

vgdb: clear all
	valgrind --tool=$(VALGRIND-TOOL) $(VALGRIND-OPTIONS) --vgdb-error=0 $(NAME) $(ARGS)

gdb: clear all
	echo "target remote | vgdb\nc" > .gdbinit
	vi .gdbinit
	gdb --args $(NAME) $(ARGS)

debug: clear all
	gdb --args $(NAME) $(ARGS)

debugf: clear all
	vi .gdbinit && gdb --args $(NAME) $(ARGS)

norme:
	while true; do sleep 2; clear; norminette $(SRCS_DIR); done

compile:
	while true; do sleep 2; clear; make; done
