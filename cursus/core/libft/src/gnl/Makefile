# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 23:58:10 by fcorri            #+#    #+#              #
#    Updated: 2023/06/09 00:19:54 by fcorri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS			=	-g
REQUIRED_CFLAGS	=	$(CFLAGS) -Wall -Wextra -Werror
CPPFLAGS		=	$(addprefix -I, $(LIBFT_DIR)/$(INC_DIR))
LDFLAGS			=	$(addprefix -L, $(LIBFT_DIR)/$(BUILD_DIR))
LDLIBS			=	$(addprefix -l, ft)

BUILD_DIR		=	build
INC_DIR			=	$(BUILD_DIR)/inc
OBJS_DIR		=	$(BUILD_DIR)/obj/gnl
LIBFT_DIR		=	../..
SRCS_DIR		=	src

SRCS			=	$(SRCS_DIR)/get_next_line.c \
					$(SRCS_DIR)/get_next_line_utils.c \
#					$(SRCS_DIR)/

OBJS			=	$(SRCS:$(SRCS_DIR)%.c=$(LIBFT_DIR)/$(OBJS_DIR)%.o)

RM				=	rm -fr

all: $(LIBFT_DIR)/$(BUILD_DIR)/libft.a $(OBJS) 

$(LIBFT_DIR)/$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $< $(REQUIRED_CFLAGS) $(CPPFLAGS) -o $@

$(LIBFT_DIR)/$(BUILD_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)

fclean: clean

re: fclean all

