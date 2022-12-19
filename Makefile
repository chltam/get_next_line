# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htam <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 15:00:32 by htam              #+#    #+#              #
#    Updated: 2022/12/14 15:00:34 by htam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME := libgnl.a
FLAGS := -Werror -Wall -Wextra
files := get_next_line \
		get_next_line_utils \

$(NAME):
	gcc -c $(FLAGS) get_next_line.c get_next_line_utils.c
	ar -rcs $(NAME) get_next_line.o get_next_line_utils.o
all: $(NAME)
clean:
	rm -f $(files:%=%.o)
fclean:
	rm -f $(files:%=%.o)
	rm -f libgnl.a
re: fclean all