# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/03 07:39:12 by gahubaul          #+#    #+#              #
#    Updated: 2016/05/03 07:40:36 by gahubaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CFLAGS = -Wall -Wextra -Werror
FLAG = -lmlx -framework OpenGL -framework Appkit

GREEN = \033[33;32m
RED = \033[33;31m
YELLOW = \033[33m

LOC_SRC = srcs/

SRCS = $(addprefix $(LOC_SRC), $(SRC))

SRC =	main.c fract_image.c fractol_color.c fractol_key_keyboard.c \
		fractol_key_mouse.c fractol_print.c fractol_equation.c \
		fractol_print_message.c fractol_menu.c

all: $(NAME)
	@printf ""

$(NAME): $(SRCS)
	@printf "$(GREEN)|$(RED) Compilation de la libft\t\t"
	@make -C libft
	@printf "$(GREEN) | OK |\n"
	@printf "$(GREEN)|$(RED) Compilation du programme fractol\t"
	@gcc -o $(NAME) $(SRCS) $(FLAG) $(CFLAGS) libft/libft.a
	@printf "$(GREEN) | OK |\n"
	@printf "\n"
	@printf "$(GREEN)| The $(RED)fractol $(GREEN)file is create\t\t | OK |\n"

clean:
	@printf "\$(GREEN)|$(YELLOW) Destruction des fichiers .o libf\t"
	@make -C libft clean
	@printf "$(GREEN) | OK |\n"

fclean: clean
	@printf "\$(GREEN)|$(YELLOW) Destruction du fichier  .a libft\t"
	@make -C libft fclean
	@printf "$(GREEN) | OK |\n"
	@printf "\$(GREEN)|$(YELLOW) Destruction de l'executable fractol\t"
	@rm -f $(NAME)
	@printf "$(GREEN) | OK |\n"

back:
	@printf "\n"

help:
	@printf "$(GREEN)- make        	$(RED)(Compile)\n"
	@printf "$(GREEN)- make fclean 	$(RED)(Destruction files .O and Program)\n"
	@printf "$(GREEN)- make clean  	$(RED)(Destruction files .O)\n"
	@printf "$(GREEN)- make re    	$(RED)(Recompile)\n"

re: fclean back all

.PHONY: all fclean clean re
