# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgolear <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 13:32:01 by dgolear           #+#    #+#              #
#    Updated: 2017/01/18 13:36:41 by dgolear          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

C_INCLUDE_PATH += libft/includes/ includes/

CFLAGS += -Wall -Wextra -Werror

CFLAGS += $(foreach d, $(C_INCLUDE_PATH), -I$d)

SRCS = ft_printf/ft_printf.c \
	   ft_printf/print_adress.c \
	   ft_printf/print_unsigned.c \
	   ft_printf/print_unsigned1.c \
	   ft_printf/print_int.c \
	   ft_printf/print_int1.c \
	   ft_printf/checker.c \
	   ft_printf/conversion.c \
	   ft_printf/print_char.c \
	   ft_printf/print_string.c \

LIBFT_PATH ?= libft/

OBJS = $(patsubst ft_printf/%.c,obj/%.o,$(SRCS))

CP = cp

RM = rm -f

all: $(NAME)

$(OBJS): | obj

obj:
	@mkdir -p $@

obj/%.o: ft_printf/%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(LIBFT_PATH)/libft.a $(OBJS)
	$(CP) $(LIBFT_PATH)/libft.a $(NAME)
	$(AR) -rcs $(NAME) $^

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

rec: fclean all
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

.PHONY: all clean fclean re $(LIBFT_PATH)/libft.a
