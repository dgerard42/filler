NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

SRCS = 	ft_itoa.c\
		ft_strchr.c \
		ft_strlen.c \
		ft_strstr.c \
		ft_memalloc.c \
		ft_putchar.c \
		ft_strclr.c \
		ft_strmap.c \
		ft_strsub.c \
		ft_memccpy.c \
		ft_putchar_fd.c \
		ft_strcmp.c \
		ft_strmapi.c \
		ft_strtrim.c \
		ft_atoi.c \
		ft_memchr.c \
		ft_putendl.c \
		ft_strcpy.c \
		ft_strncat.c \
		ft_tolower.c \
		ft_bzero.c \
		ft_memcmp.c \
		ft_putendl_fd.c \
		ft_strdel.c \
		ft_strncmp.c \
		ft_toupper.c \
		ft_isalnum.c \
		ft_memcpy.c \
		ft_putnbr.c \
		ft_strdup.c \
		ft_strncpy.c \
		ft_isalpha.c \
		ft_memdel.c \
		ft_putnbr_fd.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_isascii.c \
		ft_memmove.c \
		ft_putstr.c \
		ft_striter.c \
		ft_strnew.c \
		ft_isdigit.c \
		ft_memset.c \
		ft_putstr_fd.c \
		ft_striteri.c \
		ft_strnstr.c \
		ft_isprint.c \
		ft_strcat.c \
		ft_strjoin.c \
		ft_strrchr.c \
		ft_strlcat.c \
		ft_strsplit.c \
		ft_customtrim.c\
		ft_2dstrnew.c\
		ft_realloc.c\
		ft_strjoini.c\
		ft_strrev.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_intarraynew.c\
		ft_2dintarray.c\
		ft_2dfreearray.c\
		get_next_line.c\
		ft_bitswap.c\
		ft_itoa_base.c\
		ft_numlen.c\
		ft_floatarraynew.c\
		ft_power.c\
		ft_numlen_ll.c\
		ft_numlen_ull.c\
		ft_power_ll.c\
		ft_power_ull.c\

OFILES = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	@ar rc $(NAME) $(OFILES)
	@echo "\033[32m[library created ( ͡° ͜ʖ ͡°)]\033[0m"

%.o: %.c
	@gcc $(CFLAGS) -c $^ -o $@
	@/bin/echo -n "❂"

clean:
	@rm -f $(OFILES)
	@echo "\033[31m[libft .o files deleted (╯°□°）╯︵ ┻━┻ ]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m[libft library deleted ᕙ(⇀‸↼‶)ᕗ ]\033[0m"

re: fclean all
