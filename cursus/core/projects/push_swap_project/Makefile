# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 18:12:28 by fcorri            #+#    #+#              #
#    Updated: 2023/08/07 18:24:02 by fcorri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	$(BUILD_DIR)/push_swap
ARGS			=	

CFLAGS			=	-g
REQUIRED_CFLAGS	=	$(CFLAGS) -Wall -Wextra -Werror
CPPFLAGS		=	$(addprefix -I, $(LIBFT_DIR)/$(INC_DIR))
LDFLAGS			=	$(addprefix -L, $(LIBFT_DIR)/$(BUILD_DIR))
LDLIBS			=	$(addprefix -l, ft)

BUILD_DIR		=	build
INC_DIR			=	$(BUILD_DIR)/inc
OBJS_DIR		=	$(BUILD_DIR)/obj
LIBFT_DIR		=	../../libft
SRCS_DIR		=	src

SRCS			=	$(SRCS_DIR)/main.c \
#					$(SRCS_DIR)/ \
#					$(SRCS_DIR)/

OBJS			=	$(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

RM				=	rm -fr

all: $(NAME)

$(NAME): $(LIBFT_DIR)/$(BUILD_DIR)/libft.a $(OBJS)
	$(CC) $(OBJS) $(REQUIRED_CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(LIBFT_DIR)/$(BUILD_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $< $(REQUIRED_CFLAGS) $(CPPFLAGS) -o $@

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

