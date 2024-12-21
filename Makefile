NAME = libutilities.a
source =  \
          ft_putchar.c \
          ft_atoi.c \
		  ft_putstr.c \
		  ft_putnbr.c

object = $(source:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : $(object) $(NAME)

$(NAME) : $(object)
	ar rc $(NAME) $(object)

clean :
	rm -f $(object)

fclean : clean
	rm -f $(NAME)

re : fclean all

.SECONDARY: $(object)

.PHONY: clean

