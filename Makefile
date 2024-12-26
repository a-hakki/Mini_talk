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

client : $(object) $(NAME)
	$(CC) $(CFLAGS) client.c $(NAME) -o client

bclient : all
	cc -Wall -Werror -Wextra client_bonus.c $(NAME) -o bclient

server : all
	cc -Wall -Werror -Wextra server.c $(NAME) -o server

bserver : all
	cc -Wall -Werror -Wextra server_bonus.c $(NAME) -o bserver

najma : bserver server bclient client


msh : fclean
	rm -rf bserver server bclient client a.out

re : fclean all

.SECONDARY: $(object)

.PHONY: clean

