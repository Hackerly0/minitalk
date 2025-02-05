CC = cc
FLAGS = -Wall -Werror -Wextra
SOURCES = ft_printf.c ft_puthexa.c ft_putnbr.c ft_putunsint.c ft_putchar.c \
	  ft_putptr.c ft_putstr.c
OBJECTS = $(SOURCES:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)
	make bonus -C ./Libft
	ar x ./Libft/libft.a
	ar rcs $@ *.o
	
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C ./Libft
	rm -f *.o

fclean: clean
	make fclean -C ./Libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
