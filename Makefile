CFLAGS = -Wall -Wextra -Werror -g
LIB = -L./ft_printf -lftprintf
CC = cc
SERVER = server
CLIENT = client

all: $(CLIENT) $(SERVER)

$(SERVER): server.c
	make -C ./ft_printf
	$(CC) $(CFLAGS) server.c $(LIB) -g -o $(SERVER)

$(CLIENT): client.c
	make -C ./ft_printf 
	$(CC) $(CFLAGS) client.c $(LIB) -g -o $(CLIENT)

clean:
	make clean -C ./ft_printf
	rm -f client.o server.o

fclean: clean
	make fclean -C ./ft_printf
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
