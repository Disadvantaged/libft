NAME  = libftprintf.a
FT_PRINTF = ft_printf/ft_printf.c ft_printf/checker.c ft_printf/conversion.c \
			ft_printf/print_int.c ft_printf/print_int1.c ft_printf/print_string.c \
			ft_printf/print_char.c
SRC = ft_*.c get_next_line.c $(FT_PRINTF)
FL = -Wall -Werror -Wextra
OBJ = $(notdir $(SRC:.c=.o))
$(NAME):
	gcc $(FL) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
all: $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean
	gcc $(FL) -c $(SRC)
	ar rc $(NAME) $(OBJ)
.PHONY: clean
