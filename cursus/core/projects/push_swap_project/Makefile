# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 18:12:28 by fcorri            #+#    #+#              #
#    Updated: 2023/09/15 14:32:42 by fcorri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	$(BUILD_DIR)/push_swap
CHECK			=	$(BUILD_DIR)/check
CHECKER			=	$(BUILD_DIR)/checker_linux
PERM			=	$(BUILD_DIR)/perm

MANY			=	7
ARGS			:=	$(shell python3 utils/generate_random_numbers.py $(MANY))
ARGS			=	1 3 5 2 4 6 7

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

checker: clear all 
	@echo $(ARGS)
	@$(NAME) $(ARGS) > commands ; cat commands | $(CHECKER) $(ARGS)
	@wc -l commands
	@rm commands

perms: clear re
	@$(CC) $(SRCS_DIR)/perm.c -o $(PERM) ; $(PERM) $(MANY) > perms

define perm =
	if [ -e "results" ]; then rm results; fi
	touch results
	if [ -e "commands" ]; then rm commands; fi
	while read line
	do
		./build/push_swap $line > commands ; cat commands | ./build/checker_linux $line | if grep KO ; then echo $line ; break ; fi
		#wc -l commands | awk -v max=12 '{ if ($1 > max) print "ERROR" }'
	done < perms
	grep -B1 KO results
endef

define tests =
	if [ -e "input" ]; then rm input; fi
	if [ -e "output" ]; then rm output; fi
	touch input output
	n=10
	for i in $(seq 1 $n)
	do
		echo $(python3 utils/generate_random_numbers.py $i) >> input
	done
	while read line
	do
		echo $line >> output
		echo $(./build/push_swap $line | ./build/checker_linux $line) >> output
	done < input
	if grep -B1 KO output ; then
		echo "\e[31mKO in at least one text.. :(\e[0m"
	else
		echo "\e[32mOK!\e[0m"
	fi
	rm input
	rm commands
endef

tests: clear re
	@$(value tests)

define test =
	if [ -e "input" ]; then rm input; fi
	if [ -e "commands" ]; then rm commands; fi
	touch input
	n=5
	echo $(python3 utils/generate_random_numbers.py $n) >> input
	while read line
	do
		echo $(./build/push_swap $line >> commands ; cat commands | ./build/checker_linux $line)
	done < input
	wc -l commands
endef

test: clear re
	@$(value test)

perm: perms
	@$(value perm)
	@rm perms

.ONESHELL:
