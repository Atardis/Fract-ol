# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/05 03:18:25 by gahubaul          #+#    #+#              #
#    Updated: 2016/03/05 03:18:31 by gahubaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol
FLAG=-lmlx -framework OpenGL -framework Appkit

SRC =	main.c \
		fract_image.c \
		fractol_color.c \
		fractol_key.c \
		fractol_print.c \
		fractol_equation.c
		
all: $(NAME)

$(NAME): $(SRC)
	@make -C libft
	@echo "\033[33;32m|\033[31m Compilation de la libft\t\t\033[33;32m | OK |"
	@gcc -o $(NAME) $(SRC) $(FLAG) libft/libft.a
	@echo "\033[33;32m|\033[31m Compilation du programme fractol\t\033[33;32m | OK |"
	@echo "\033[33;31m-----------------------------------------------"
	@echo "\033[33;32m|\033[33;32m The \033[31mfractol \033[33;32mfile is create\t\t\033[33;32m | OK |"

force:	
	@make -C libft
	@echo "\033[33;32m|\033[31m Compilation de la libft\t\t\033[33;32m | OK |"
	@gcc -o $(NAME) $(SRC) $(FLAG) libft/libft.a
	@echo "\033[33;32m|\033[31m Compilation du programme fractol\t\033[33;32m | OK |"
	@echo "\033[33;31m-----------------------------------------------"
	@echo "\033[33;32m|\033[33;32m The \033[31mfractol \033[33;32mfile is create\t\t\033[33;32m | OK |"

clean:
	@echo "\033[33;32m|\033[33m Destruction des fichiers .o libf\t\033[33;32m | OK |"
	@make -C libft clean

fclean: clean
	@make -C libft fclean
	@echo "\033[33;32m|\033[33m Destruction du fichier  .a libft\t\033[33;32m | OK |"
	@rm -f $(NAME)
	@echo "\033[33;32m|\033[33m Destruction de l'executable fractol\t\033[33;32m | OK |"

line:
	@echo "\033[33;31m-----------------------------------------------"

re: fclean line all

.PHONY: all line fclean clean re force
