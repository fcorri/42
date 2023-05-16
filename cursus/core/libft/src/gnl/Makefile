# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 09:42:39 by fcorri            #+#    #+#              #
#    Updated: 2023/05/12 10:26:59 by fcorri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	gnl

CFLAGS			=	-g
REQUIRED_CFLAGS	=	$(CFLAGS) -Wall -Wextra -Werror
CPPFLAGS		=	-I$(INC_DIR)
LDFLAGS			=	-L$(LIBFT_DIR)/build
LDLIBS			=	-lft

BUILD_DIR		=	../../build
INC_DIR			=	$(BUILD_DIR)/inc
OBJS_DIR		=	obj
LIBFT_DIR		=	../..
SRCS_DIR		=	.

SRCS			=	$(SRCS_DIR)/get_next_line.c \
					$(SRCS_DIR)/get_next_line_utils.c \
					$(SRCS_DIR)/main.c \
#					$(SRCS_DIR)/

OBJS			=	$(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

RM				=	rm -fr

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(REQUIRED_CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $< $(REQUIRED_CFLAGS) $(CPPFLAGS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

