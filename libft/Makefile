# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/09 18:10:20 by tamarant          #+#    #+#              #
#    Updated: 2019/11/28 21:09:43 by tamarant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
	  ft_strlen.c ft_isalpha.c ft_isdigit.c ft_atoi.c ft_strncpy.c \
	  ft_strncmp.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
	  ft_tolower.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
	  ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	  ft_strtrim.c ft_putendl.c ft_putnbr.c ft_itoa.c ft_strnew.c \
	  ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	  ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c ft_strdel.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_strcat.c ft_strncat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	  ft_strnstr.c ft_strlcat.c ft_strsplit.c ft_sqrt.c \
	  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	  ft_iterative_factorial.c ft_free.c ft_iterative_power.c \
	  ft_strjoin_free.c ft_lstmap.c ft_countwords.c \
	  get_next_line.c ft_clear_table.c ft_atoi_base.c \
	  number_len_ll.c number_len.c number_len_ull.c \
	  ft_llutoa.c ft_lltoa.c ulltoa_base.c itoa_base.c


OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
				gcc $(FLAGS) -I libft.h -c $(SRC)
				ar rc $(NAME) $(OBJ)
				ranlib $(NAME)

clean:
				rm -rf $(OBJ)

fclean: clean
				rm -rf $(NAME)

re: fclean all
