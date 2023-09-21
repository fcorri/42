# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 18:12:28 by fcorri            #+#    #+#              #
#    Updated: 2023/09/21 15:27:10 by fcorri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	$(BUILD_DIR)/push_swap
CHECK			=	$(BUILD_DIR)/check
CHECKER			=	$(BUILD_DIR)/checker_linux
PERM			=	$(BUILD_DIR)/perm

MANY			=	20
ARGS			:=	$(shell python3 utils/generate_random_numbers.py $(MANY))
ARGS			=	$(shell cat input)

CFLAGS			=	-g3
REQUIRED_CFLAGS	=	$(CFLAGS) -Wall -Wextra -Werror
CPPFLAGS		=	$(addprefix -I, $(LIBFT_DIR)/$(INC_DIR))
LDFLAGS			=	$(addprefix -L, $(LIBFT_DIR)/$(BUILD_DIR))
LDLIBS			=	$(addprefix -l, ft)

BUILD_DIR		=	build
INC_DIR			=	$(BUILD_DIR)/inc
OBJS_DIR		=	$(BUILD_DIR)/obj
LIBFT_DIR		=	../../libft
SRCS_DIR		=	src
P_HEADER		=	$(SRCS_DIR)/push_swap_p.h

SRCS			=	$(SRCS_DIR)/main.c \
					$(SRCS_DIR)/init.c \
					$(SRCS_DIR)/check.c \
					$(SRCS_DIR)/print.c \
					$(SRCS_DIR)/utils.c \
					$(SRCS_DIR)/stack.c \
					$(SRCS_DIR)/free.c \
					$(SRCS_DIR)/queue.c \
					$(SRCS_DIR)/order.c \
					$(SRCS_DIR)/swap.c \
					$(SRCS_DIR)/min_ops.c \
					$(SRCS_DIR)/push.c \
					$(SRCS_DIR)/rotate.c \
					$(SRCS_DIR)/reverse.c \

OBJS			=	$(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

RM				=	rm -fr

all: $(NAME)

$(NAME): $(LIBFT_DIR)/$(BUILD_DIR)/libft.a $(OBJS)
	$(CC) $(OBJS) $(REQUIRED_CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(LIBFT_DIR)/$(BUILD_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(P_HEADER)
	@mkdir -p $(@D)
	$(CC) -c $< $(REQUIRED_CFLAGS) $(CPPFLAGS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

clear:
	clear

run: clear re
	$(CC) -c $(SRCS_DIR)/order.c $(REQUIRED_CFLAGS) $(CPPFLAGS) -DCHECK=0 -o $(OBJS_DIR)/order.o
	$(CC) $(OBJS) $(REQUIRED_CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	$(NAME) $(ARGS)

check: clear re
	$(CC) -c $(SRCS_DIR)/order.c $(REQUIRED_CFLAGS) $(CPPFLAGS) -DCHECK=1 -o $(OBJS_DIR)/order.o
	$(CC) $(OBJS) $(REQUIRED_CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(CHECK)
	$(CHECK) $(ARGS)

mem: clear re
	valgrind --track-origins=yes --leak-check=full $(NAME) $(ARGS)

vgdb: clear re
	valgrind --track-origins=yes --vgdb-error=0 $(NAME) $(ARGS)

gdb: clear re
	echo "target remote | vgdb" > .gdbinit
	echo "c" >> .gdbinit
	gdb $(NAME)

debug: clear re
	gdb --args $(NAME) $(ARGS)

debugf: clear re
	vi .gdbinit && gdb --args $(NAME) $(ARGS)

debugc: clear re
	$(CC) -c $(SRCS_DIR)/order.c $(REQUIRED_CFLAGS) $(CPPFLAGS) -DCHECK=1 -o $(OBJS_DIR)/order.o
	$(CC) $(OBJS) $(REQUIRED_CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(CHECK)
	gdb --args $(CHECK) $(ARGS)

debugcf: clear re
	$(CC) -c $(SRCS_DIR)/order.c $(REQUIRED_CFLAGS) $(CPPFLAGS) -DCHECK=1 -o $(OBJS_DIR)/order.o
	$(CC) $(OBJS) $(REQUIRED_CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(CHECK)
	vi .gdbinit && gdb --args $(CHECK) $(ARGS)

checker: clear re 
	$(NAME) $(ARGS) | $(CHECKER) $(ARGS)

# testa tutte le permutazioni di lunghezza $(MANY) e si dovrebbe fermare quando checker restituisce KO, stampando il test fallito. Togliendo il commento si possono contare le operazioni e capire se viene sforato il massimo consentito, impostato su max
define perm =
	if [ -e "commands" ]; then rm commands; fi
	touch commands
	while read line
	do
		./build/push_swap $line > commands ; cat commands | ./build/checker_linux $line | if grep KO ; then break ; echo $line ; fi
		#wc -l commands | awk -v max=12 '{ if ($1 > max) print "ERROR" }'
	done < perms
	rm perms
endef

perms: clear re
	cat input
	$(CC) $(SRCS_DIR)/perm.c -o $(PERM) ; $(PERM) $(MANY) > perms
	$(value perm)

# testa un input con n numeri casuali
define test =
	n=500
	echo $(python3 utils/generate_random_numbers.py $n) > input
	./build/push_swap $(cat input) > commands ; cat commands | ./build/checker_linux $(cat input)
	wc -l commands
endef

test: clear re
	$(value test)

.ONESHELL:
