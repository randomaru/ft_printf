# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/17 18:16:44 by tamarant          #+#    #+#              #
#    Updated: 2019/12/17 20:33:51 by tamarant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = check.c \
		fill_final.c \
		find.c \
		find_str_size.c \
		float_maker.c \
		float_new_free.c \
		float_put.c \
		floats.c \
		ft_printf.c \
		new_str.c \
		other.c \
		parse_format.c \
		pf_format.c \
		pf_free.c \
		pf_lib.c \
		print_check.c \

INC = inc/ft_printf.h

SRC = $(addprefix src/,$(FILES))

OBJ = $(addprefix obj/,$(FILES:.c=.o))

LIB = libft/libft.a

LIBFT_DIR = libft/

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

check_lib:
	$(MAKE) -C $(LIBFT_DIR)

obj/%.o: src/%.c
	@mkdir -p obj/
	@gcc $(FLAGS) -I $(INC) -o $@ -c $<

$(NAME): $(OBJ) check_lib
	cp $(LIB) $(NAME)
	ar rc $(NAME) $(OBJ)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)
	rm -rf ./obj

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -rf ./obj

re: fclean $(NAME)