# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenani <abenani@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/22 14:53:22 by abenani           #+#    #+#              #
#    Updated: 2019/12/07 15:58:47 by abenani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FILES = main.c events.c events_2.c tools.c tools_2.c mandelbrot.c julia.c burning_ship.c sets.c multibrot1.c multibrot2.c 
DIR = srcs
SLIB = libft/libft.a
CC = gcc -Wall -Wextra -Werror
SRCS = $(addprefix srcs/, $(FILES))
LIB = inc/fractol.h
INCLUDE = /usr/local/include
LIBSNFRAMES = /usr/local/lib -lmlx -framework OpenGL -framework Appkit
OBJ = $(FILES:.c=.o)
SRCOBJ = $(addprefix srcs/, $(OBJ))


all:$(NAME)
$(NAME): $(SRCOBJ) $(LIB)
		@cd libft && make
		$(CC) -I $(INCLUDE) -o $(NAME) $(SRCS) -L $(LIBSNFRAMES) $(SLIB)
clean:
		rm -f $(SRCOBJ)
		cd libft && make fclean
fclean: clean
		rm -f $(NAME)
re: fclean all
