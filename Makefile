NAME = libutilities.a
NAME2 = libutilities2.a
source =  \
          ft_putchar.c \
          ft_atoi.c \
		  ft_putstr.c \
		  ft_putnbr.c

object = $(source:.c=.o)
object_bonus = $(source:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : $(object) $(NAME)

$(NAME) : $(object)
	ar rc $(NAME) $(object)
	$(CC) $(CFLAGS) client.c $(NAME) -o client
	$(CC) $(CFLAGS) server.c $(NAME) -o server


bonus : $(object_bonus) $(NAME2)

$(NAME2) : $(object_bonus)
	ar rc $(NAME2) $(object_bonus)
	$(CC) $(CFLAGS) client_bonus.c $(NAME2) -o client_bonus
	$(CC) $(CFLAGS) server_bonus.c $(NAME2) -o server_bonus

clean :
	rm -f $(object) $(object_bonus)

fclean : clean
	rm -f $(NAME) $(NAME2)

msh : fclean
	rm -rf server_bonus server client_bonus client a.out

re : fclean all

.SECONDARY: $(object)

.PHONY: clean