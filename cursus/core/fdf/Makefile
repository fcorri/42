# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 00:37:18 by fcorri            #+#    #+#              #
#    Updated: 2023/08/03 11:45:37 by fcorri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	$(BUILD_DIR)/fdf
ARGS			=	../maps/42.fdf

CFLAGS			=	-g3
REQUIRED_CFLAGS	=	$(CFLAGS) -Wall -Wextra -Werror
CPPFLAGS		=	$(addprefix -I, $(LIBFT_DIR)/$(INC_DIR) /usr/include $(MLX_DIR))
LDFLAGS			=	$(addprefix -L, $(LIBFT_DIR)/$(BUILD_DIR) $(MLX_DIR) /usr/lib)
LDLIBS			=	$(addprefix -l, ft mlx_Linux Xext X11 m z)

BUILD_DIR		=	build
INC_DIR			=	$(BUILD_DIR)/inc
OBJS_DIR		=	$(BUILD_DIR)/obj
LIBFT_DIR		=	../libft
SRCS_DIR		=	src
MLX_DIR			=	../minilibx-linux

SRCS			=	camera.c \
					colors.c \
					decorators.c \
					for_each_point.c \
					free.c \
					init.c \
					keys.c \
					line.c \
					main.c \
					math_utils.c \
					print.c \
					projection.c \
					quaternions.c \
					render.c \
					rotate_ccw.c \
					rotate_cw.c \
					transformations.c \
					utils.c \
					vectors.c \
					zoom.c

OBJS			=	$(SRCS:%.c=$(OBJS_DIR)/%.o)

RM				=	rm -fr

all: $(NAME)

$(NAME): $(LIBFT_DIR)/$(BUILD_DIR)/libft.a $(OBJS)
	$(CC) $(OBJS) $(REQUIRED_CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(LIBFT_DIR)/$(BUILD_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(SRCS_DIR)/fdf_p.h
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
	clear; $(NAME) $(ARGS)

mem: clear all
	clear ; valgrind $(NAME) $(ARGS)

debug: clear all
	clear ; vi .gdbinit && gdb --args $(NAME) $(ARGS)
