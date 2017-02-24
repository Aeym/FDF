# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ealrick <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/25 14:07:37 by ealrick           #+#    #+#              #
#    Updated: 2017/01/27 16:59:54 by ealrick          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c draw.c mlx.c utility.c geom.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADER = -I./

FLAG_MLX = -L/usr/local/lib/ -I/usr/local/include -lm -lmlx -framework OpenGL -framework AppKit

LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	@make re -C ./libft/
	@echo "\033[1m\033[32m[ ✔ ]Compilation succes :\033[0m libft"
	@gcc $(FLAGS) -o $(NAME) $(SRCS) $(HEADER) $(FLAG_MLX) $(LIBFT)
	@echo "\033[1m\033[32m[ ✔ ]Compilation succes :\033[0m $(NAME)"

clean :
	@rm -f $(OBJ)
	@echo "\033[1m\033[31m[ ✔ ]Deleting succes :\033[0m OBJS"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[1m\033[31m[ ✔ ]Deleting succes :\033[0m $(NAME)"

re : fclean all

