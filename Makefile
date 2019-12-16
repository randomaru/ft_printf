
NAME = libftprintf.a

H_NAME = printf.h

LIBFT_DIR = ./libft/


FLAGS = -Wall -Wextra -Werror -g

SRC_C = ft_printf.c pf_format.c check.c find.c fill_final_str.c floats.c SVETA_pf_itoa.c \
new_str.c parse_format.c find_str_size.c pf_strcpy.c

SRC_O = $(SRC_C:.c=.o)

all: $(NAME)

check_lib:
	$(MAKE) -C $(LIBFT_DIR)

*.o: $(SRC_C)
	gcc -c $(SRC_C) -I $(H_NAME)

$(NAME): *.o check_lib
	cp $(LIBFT_DIR)libft.a $(NAME)
	ar rc $(NAME) $(SRC_O)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(SRC_O)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean $(NAME)
