# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <fcorri@student.42firenze.it>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 13:00:45 by fcorri            #+#    #+#              #
#    Updated: 2024/03/04 16:56:36 by fcorri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	$(BUILD_DIR)/megaphone
ARGS			=	Damnit " ! " "Sorry students, I thought this thing was off."

VALGRIND-TOOL	=	memcheck
VALGRIND-OPTIONS=	

CC				=	c++
CFLAGS			=	-g
REQUIRED_CFLAGS	=	$(CFLAGS) -Wall -Wextra -Werror -std=c++98
CPPFLAGS		=	$(addprefix -I, )
LDFLAGS			=	$(addprefix -L, )
LDLIBS			=	$(addprefix -l, )

BUILD_DIR		=	build
INC_DIR			=	$(BUILD_DIR)/inc
OBJS_DIR		=	$(BUILD_DIR)/obj
SRCS_DIR		=	src
P_HEADER		=	

SRCS			=	$(SRCS_DIR)/megaphone.cpp \
#					$(SRCS_DIR)/ \
#					$(SRCS_DIR)/

OBJS			=	$(SRCS:$(SRCS_DIR)%.cpp=$(OBJS_DIR)%.o)

RM				=	rm -fr

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(REQUIRED_CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp $(P_HEADER)
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
	valgrind --tool=$(VALGRIND-TOOL) $(VALGRIND-OPTIONS) $(NAME) $(ARGS)

vgdb: clear all
	valgrind --tool=$(VALGRIND-TOOL) $(VALGRIND-OPTIONS) --vgdb-error=0 $(NAME) $(ARGS)

gdb: clear all
	echo "target remote | vgdb\nc" > .gdbinit
	gdb --args $(NAME) $(ARGS)

debug: clear all
	gdb --args $(NAME) $(ARGS)

debugf: clear all
	vi .gdbinit && gdb --args $(NAME) $(ARGS)

