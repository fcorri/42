# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: filippo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 18:47:08 by filippo           #+#    #+#              #
#    Updated: 2024/02/28 17:01:49 by fcorri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT			=	$(BUILD_DIR)/client
SERVER			=	$(BUILD_DIR)/server

CFLAGS			=	-g
REQUIRED_CFLAGS	=	$(CFLAGS) -Wall -Wextra -Werror
CPPFLAGS		=	-I$(LIBFT_DIR)/$(BUILD_DIR)/inc
LDFLAGS			=	-L$(LIBFT_DIR)/$(BUILD_DIR)
LDLIBS			=	-lft

BUILD_DIR		=	build
OBJS_DIR		=	$(BUILD_DIR)/obj
LIBFT_DIR		=	../../libft
SRCS_DIR		=	src

CLIENT_SRCS		=	$(SRCS_DIR)/client.c
CLIENT_OBJS		=	$(CLIENT_SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

SERVER_SRCS		=	$(SRCS_DIR)/server.c
SERVER_OBJS		=	$(SERVER_SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

UTILS_SRCS		=	$(SRCS_DIR)/utils.c
UTILS_OBJS		=	$(UTILS_SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

RM				=	rm -fr

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS) $(UTILS_OBJS) $(LIBFT_DIR)/$(BUILD_DIR)/libft.a
	$(CC) $(CLIENT_OBJS) $(UTILS_OBJS) $(REQUIRED_CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $@

$(SERVER): $(SERVER_OBJS) $(UTILS_OBJS) $(LIBFT_DIR)/$(BUILD_DIR)/libft.a
	$(CC) $(SERVER_OBJS) $(UTILS_OBJS) $(REQUIRED_CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $< $(REQUIRED_CFLAGS) $(CPPFLAGS) -o $@

$(LIBFT_DIR)/$(BUILD_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

bonus: all

clean:
	$(RM) $(CLIENT_OBJS)
	$(RM) $(SERVER_OBJS)

fclean: clean
	$(RM) $(CLIENT) $(SERVER) 

re: fclean all
