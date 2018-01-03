# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgerard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 17:24:50 by dgerard           #+#    #+#              #
#    Updated: 2017/11/07 17:24:52 by dgerard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dgerard.filler

FLAGS = -Wall -Werror -Wextra -g

LIBFT = libft/libft.a\

PRINTF = printf/libftprintf.a\

SRCS =	main.c\
		perceive.c\
		plan.c\
		attack.c\
		# kane_alloc_wrap.c\

ODIR = ofiles

OFILES = $(addprefix $(ODIR)/,$(SRCS:.c=.o))

$(ODIR)/%.o: %.c
	@gcc $(FLAGS) -c $^ -o $@
	@/bin/echo -n "❂❂❂❂"

#are both of these nessecary though? ^ && v ?
%.o: %.c
	@gcc $(FLAGS) -c $^ -o $@
	@/bin/echo -n "❂❂❂❂❂"

all: $(NAME)

$(NAME): $(OFILES)
	@echo "\033[32m[filler .o files created ( ͡° ͜ʖ ͡°)]\033[0m"
	@make -C libft/
	@make -C printf/
	@gcc $(FLAGS) -o $@ $(OFILES) $(LIBFT) $(PRINTF)
	@echo "\033[32m[filler executable created ( ͡° ͜ʖ ͡°)]\033[0m"

$(OFILES): | $(ODIR)

$(ODIR):
	@mkdir $(ODIR)

clean:
	@make -C libft/ clean
	@make -C printf/ clean
	@rm -rf $(ODIR)
	@echo "\033[31m[filler .o files deleted (╯°□°）╯︵ ┻━┻ ]\033[0m"

fclean: clean
	@/bin/rm -f rm $(NAME)
	@make -C libft/ fclean
	@make -C printf/ fclean
	@echo "\033[31m[filler executable deleted ᕙ(⇀‸↼‶)ᕗ ]\033[0m"

re: fclean all
