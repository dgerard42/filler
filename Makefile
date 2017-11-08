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

FLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a\

SRCS = main.c\
	   parser.c\
	   placer.c\
	   reader.c\

OFILES = $(addprefix $(ODIR)/,$(SRCS:.c=.o))

$(ODIR)/%.o: %.c
	@gcc $(FLAGS) -c $^ -o $@
	@/bin/echo -n "❂❂❂❂"

#are both of these nessecary though? ^ && v ?
%.o: %.c
	@gcc $(FLAGS) -c $^ -o $@
	@/bin/echo -n "❂❂❂❂❂"

all: $(NAME)

$(NAME): $(OFILES) $(FLAGS)
	@make -C libs/libft/
	@make -C libs/minilibx/
	@gcc $(FLAGS) -o $@ $(OFILES) $(LIBFT)
	@echo "\033[32m[filler created ( ͡° ͜ʖ ͡°)]\033[0m"

$(OFILES): | $(ODIR)

clean:
	@make -C libft/ clean
	@rm -rf $(ODIR)
	@echo "\033[31m[.o files deleted (╯°□°）╯︵ ┻━┻ ]\033[0m"

fclean: clean
	@/bin/rm -f rm $(NAME)
	@make -C libft/ fclean
	@echo "\033[31m[executable deleted ᕙ(⇀‸↼‶)ᕗ ]\033[0m"

re: fclean all
