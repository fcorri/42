# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 16:34:06 by fcorri            #+#    #+#              #
#    Updated: 2023/03/23 15:56:10 by fcorri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

LIBFT		=	../
SRC_DIR		=	./src
OBJ_DIR		=	./obj
PRNTRS_DIR	= $(SRC_DIR)/printers

AR			=	ar crs
RM			=	rm -fr

SRCS		=	ft_printf.c \
				$(SRC_DIR)/specification.c \
				$(SRC_DIR)/utils.c \
				$(PRNTRS_DIR)/printer.c \
				$(PRNTRS_DIR)/default_printer.c \
				$(PRNTRS_DIR)/default_num_printer.c \
				$(PRNTRS_DIR)/char_printer.c \
				$(PRNTRS_DIR)/string_printer.c \
				$(PRNTRS_DIR)/pointer_printer.c \
				$(PRNTRS_DIR)/decimal_integer_printer.c \
				$(PRNTRS_DIR)/unsigned_printer.c \
				$(PRNTRS_DIR)/hex_printer.c \
				$(PRNTRS_DIR)/min_hex_printer.c \
				$(PRNTRS_DIR)/max_hex_printer.c \
				$(PRNTRS_DIR)/percentage_printer.c

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: all
