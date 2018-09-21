# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                       +:+ +:+         +:+      #
#    By: fkhan <marvin@4 2.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 14:49:15 by fkhan             #+#    #+#              #
#    Updated: 2018/09/19 12:46:02 by fkhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Wolf3D
FLAG = -Wall -Werror -Wextra
GC = gcc
MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
		$(GC) $(FLAG) $(MLX) Wolf3D.c -I libft/include -L libft/ -lft
