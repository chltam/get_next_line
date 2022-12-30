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
bonus := libgnlb.a
FLAGS := -Werror -Wall -Wextra
files := get_next_line \
		get_next_line_utils \

bonusfiles := get_next_line_bonus \
		get_next_line_utils_bonus \

$(NAME):
	gcc -c $(FLAGS) get_next_line.c get_next_line_utils.c
	ar -rcs $(NAME) get_next_line.o get_next_line_utils.o
	gcc test.c -L. -lgnl -o test

bonus: 
	gcc -c $(FLAGS) get_next_line_bonus.c get_next_line_utils_bonus.c
	ar -rcs $(bonus) get_next_line_bonus.o get_next_line_utils_bonus.o
	gcc test.c -L. -lgnlb -o bonustest

all: $(NAME) bonus
clean:
	rm -f $(files:%=%.o) $(bonusfiles:%=%.o)
fclean:
	rm -f $(files:%=%.o) $(bonusfiles:%=%.o)
	rm -f libgnl.a libgnlb.a
re: fclean all