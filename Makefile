NAME  = libftt.a
FT_PRINTF = ft_printf.c checker.c conversion.c print_int.c print_string.c \
			print_char.c print_adress.c print_unsigned.c print_int1.c \
			print_unsigned1.c
SRC = ft_*.c get_next_line.c $(addprefix ft_printf/,$(FT_PRINTF))
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
rec: re
	rm -f $(OBJ)
.PHONY: clean
