# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 15:35:30 by jjuntune          #+#    #+#              #
#    Updated: 2022/04/19 15:29:02 by jjuntune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBRERY = libft/libft.a

FILES = main.c keyhooks.c image_calculation.c

OFILES = $(FILES:.c=.o)

COMP = gcc -Wall -Wextra -Werror

INCLUDES = -I /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OFILES) $(LIBRERY)
	$(COMP) $(OFILES) $(LIBRERY) $(INCLUDES) -o $(NAME)

%.o:%.c
	$(COMP) $(FLAGS) -c $(FILES) $<

$(LIBRERY):
	make -C libft/

clean:
	rm -f $(OFILES)
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all