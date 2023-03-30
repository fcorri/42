# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 15:29:43 by fcorri            #+#    #+#              #
#    Updated: 2023/03/08 16:07:26 by fcorri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	$(BUILDS_DIR)/libft.a

CFLAGS		=	-Wall -Wextra -Werror

SRCS_DIR	=	./src
LIB_DIR		=	$(SRCS_DIR)/lib
BONUS_DIR	=	$(LIB_DIR)/bonus
UTILS_DIR	=	$(LIB_DIR)/utils
BUILDS_DIR	=	./build
OBJS_DIR	=	$(BUILDS_DIR)/obj

SRCS		=	$(LIB_DIR)/ft_atoi.c \
				$(LIB_DIR)/ft_bzero.c \
				$(LIB_DIR)/ft_calloc.c \
				$(LIB_DIR)/ft_isalnum.c \
				$(LIB_DIR)/ft_isalpha.c \
				$(LIB_DIR)/ft_isascii.c \
				$(LIB_DIR)/ft_isdigit.c \
				$(LIB_DIR)/ft_isprint.c \
				$(LIB_DIR)/ft_itoa.c \
				$(LIB_DIR)/ft_memchr.c \
				$(LIB_DIR)/ft_memcmp.c \
				$(LIB_DIR)/ft_memcpy.c \
				$(LIB_DIR)/ft_memmove.c \
				$(LIB_DIR)/ft_memset.c \
				$(LIB_DIR)/ft_putchar_fd.c \
				$(LIB_DIR)/ft_putendl_fd.c \
				$(LIB_DIR)/ft_putnbr_fd.c \
				$(LIB_DIR)/ft_putstr_fd.c \
				$(LIB_DIR)/ft_split.c \
				$(LIB_DIR)/ft_strchr.c \
				$(LIB_DIR)/ft_strdup.c \
				$(LIB_DIR)/ft_striteri.c \
				$(LIB_DIR)/ft_strjoin.c \
				$(LIB_DIR)/ft_strlcat.c \
				$(LIB_DIR)/ft_strlcpy.c \
				$(LIB_DIR)/ft_strlen.c \
				$(LIB_DIR)/ft_strmapi.c \
				$(LIB_DIR)/ft_strncmp.c \
				$(LIB_DIR)/ft_strndup.c \
				$(LIB_DIR)/ft_strnstr.c \
				$(LIB_DIR)/ft_strrchr.c \
				$(LIB_DIR)/ft_strtrim.c \
				$(LIB_DIR)/ft_substr.c \
				$(LIB_DIR)/ft_tolower.c \
				$(LIB_DIR)/ft_toupper.c \
				$(UTILS_DIR)/ft_malloc_soul.c \
				$(UTILS_DIR)/ft_memutils1.c \
				$(UTILS_DIR)/ft_memutils2.c \

BONUS_SRCS	=	$(BONUS_DIR)/ft_lstadd_back.c \
				$(BONUS_DIR)/ft_lstadd_front.c \
				$(BONUS_DIR)/ft_lstclear.c \
				$(BONUS_DIR)/ft_lstdelone.c \
				$(BONUS_DIR)/ft_lstiter.c \
				$(BONUS_DIR)/ft_lstlast.c \
				$(BONUS_DIR)/ft_lstmap.c \
				$(BONUS_DIR)/ft_lstnew.c \
				$(BONUS_DIR)/ft_lstsize.c \

OBJS		=	$(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)
BONUS_OBJS	=	$(BONUS_SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

AR			=	ar -crs
RM			=	rm -fr

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

$(OBJS_DIR)/%.o: $(addprefix $(SRCS_DIR)/, $(notdir %.c))
	cc -c $< -o $@

re: fclean all

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
