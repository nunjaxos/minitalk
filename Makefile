CC = cc
CFLAGS = -Wall -Wextra -Werror

CLN = client.c ft_atoi.c
SRV = server.c ft_putnbr.c
CLN2 = client_bonus.c ft_atoi.c
SRV2 = server_bonus.c ft_putnbr.c

COBJ = $(CLN:.c=.o)
SOBJ = $(SRV:.c=.o)
COBJ2 = $(CLN2:.c=.o)
SOBJ2 = $(SRV2:.c=.o)

NAME1 = client
NAME2 = server
NAME3 = client_bonus
NAME4 = server_bonus

all : $(NAME1)

$(NAME1): $(COBJ) $(NAME2)
	$(CC) $(CFLAGS) $(COBJ) -o $(NAME1)

$(NAME2): $(SOBJ)
	$(CC) $(CFLAGS) $(SOBJ) -o $(NAME2)

bonus : $(NAME3)

$(NAME3): $(COBJ2) $(NAME4)
	$(CC) $(CFLAGS) $(COBJ2) -o $(NAME3)

$(NAME4): $(SOBJ2)
	$(CC) $(CFLAGS) $(SOBJ2) -o $(NAME4)

clean : 
	@rm -f $(COBJ) $(SOBJ) $(COBJ2) $(SOBJ2)
fclean : clean
	@rm -f $(NAME1) $(NAME2) $(NAME3) $(NAME4)

re: fclean all

# .PHONY all clean fclean re
