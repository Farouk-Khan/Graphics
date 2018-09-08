# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkhan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/18 10:41:59 by fkhan             #+#    #+#              #
#    Updated: 2018/08/03 06:01:00 by fkhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TAG = gcc
NAME = fdf.a
FLAG = -Wall -Werror -Wextra
INC_LIB = -I libft/includes -L libft/ -lft
MLX = -lmlx -framework OpenGL -framework AppKit
SRC = main.c map_arr.c display_map.c draw_map.c draw_width.c set_map.c\
	  average_height.c draw_line.c draw_up.c draw_down.c memalloc_arr.c\
	  arr_size.c hook.c

all: $(NAME)

$(NAME):
	$(TAG) $(SRC) $(FLAG) $(MLX) $(INC_LIB)

clean:
		rm -f $(OBJECT)

fclean: clean
		rm -f fdf.a

re: fclean all
