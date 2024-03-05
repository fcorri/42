# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <fcorri@student.42firenze.it>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 20:11:06 by fcorri            #+#    #+#              #
#    Updated: 2024/03/06 00:43:42 by filippo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	$(BUILD_DIR)/test
ARGS			=	

VALGRIND-TOOL	=	memcheck
VALGRIND-OPTIONS=	

CC				=	c++
CFLAGS			=	-g
REQUIRED_CFLAGS	=	$(CFLAGS) -Wall -Wextra -Werror -std=c++98
CPPFLAGS		=	$(addprefix -I, $(INC_DIR))
LDFLAGS			=	$(addprefix -L, )
LDLIBS			=	$(addprefix -l, )

TEST			=	Contact

BUILD_DIR		=	build
INC_DIR			=	../$(BUILD_DIR)/inc
OBJS_DIR		=	$(BUILD_DIR)/obj
SRCS_DIR		=	src
P_HEADER		=	$(INC_DIR)/$(TEST).hpp

SRCS			=	$(SRCS_DIR)/main.cpp \
					../$(SRCS_DIR)/$(TEST).cpp

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

PHONY:
	all clean fclean re clear run mem vgdb gdb debug debugf

