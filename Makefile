CFLAGS = -Wall -Wextra -Werror
LIB = -L./ft_printf -lftprintf
CC = cc
SERVER = server
CLIENT = client
OBJS = server.o client.o ft_realloc.o

all: $(CLIENT) $(SERVER)

ft_realloc.o: ft_realloc.c
	$(CC) $(CFLAGS) -c ft_realloc.c

$(SERVER): server.c ft_realloc.o
	make -C ./ft_printf
	$(CC) $(CFLAGS) server.c ft_realloc.o $(LIB) -o $(SERVER)

$(CLIENT): client.c ft_realloc.o
	make -C ./ft_printf 
	$(CC) $(CFLAGS) client.c ft_realloc.o $(LIB) -o $(CLIENT)

clean:
	make clean -C ./ft_printf
	rm -f client.o server.o ft_realloc.o

fclean: clean
	make fclean -C ./ft_printf
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
