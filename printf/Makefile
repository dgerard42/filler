# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgerard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/18 10:57:42 by dgerard           #+#    #+#              #
#    Updated: 2017/11/09 13:51:52 by dgerard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

SRCS = 	ft_printf.c\
		check_flags.c\
		parse_args.c\
		print_letters.c\
		print_numbers.c\
		outputs.c\

LIBFT = libft/ft_atoi.c\
		libft/ft_isdigit.c\
		libft/ft_strlen.c\
		libft/ft_power_ll.c\
		libft/ft_power_ull.c\
		libft/ft_numlen_ll.c\
		libft/ft_numlen_ull.c\

LIBFTDIR = libft

ODIR = ofiles

OFILES = $(addprefix $(ODIR)/,$(SRCS:.c=.o))

LIBFTO = $(LIBFT:.c=.o)

$(ODIR)/%.o: %.c
	@gcc $(CFLAGS) -c $^ -o $@
	@/bin/echo -n "❂❂❂❂"

%.o: %.c
	@gcc $(CFLAGS) -c $^ -o $@
	@/bin/echo -n "❂❂❂❂"

all: $(NAME)

$(NAME): $(OFILES) $(LIBFTO)
	@ar rc $(NAME) $(OFILES) $(LIBFTO)
	@echo "\033[32m[libftprintf created ( ͡° ͜ʖ ͡°)]\033[0m"

$(OFILES): | $(ODIR)

$(ODIR):
	@mkdir $(ODIR)

clean:
	@rm -f $(LIBFTO)
	@rm -rf $(ODIR)
	@echo "\033[31m[ftprintf .o files deleted (╯°□°）╯︵ ┻━┻ ]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m[libftprintf library deleted ᕙ(⇀‸↼‶)ᕗ ]\033[0m"

re: fclean all
