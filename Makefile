NAME=fractol
FLAG=-lmlx -framework OpenGL -framework Appkit

SRC =	src/main.c \
		src/fract_image.c \
		src/fractol_color.c \
		src/fractol_key_keyboard.c \
		src/fractol_key_mouse.c \
		src/fractol_print.c \
		src/fractol_equation.c \
		src/fractol_print_message.c \
		src/fractol_menu.c

all: $(NAME)
	@echo "\033[33;31m-----------------------------------------------"
	@echo "\033[33;32m|\033[33;32m   Executable  \033[33;31mFractol   \033[33;32mprésent \t\033[33;32m | OK |"
	@echo "\033[33;31m-----------------------------------------------"

$(NAME): $(SRC)
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

name:
	@echo "\033[33;31m------------------------------------------------------------------------------"
	@echo "\033[33;32m    ######## ########     ###     ######  ########    #     #######  ##"
	@echo "\033[33;32m    ##       ##     ##   ## ##   ##    ##    ##       #    ##     ## ##"
	@echo "\033[33;32m    ##       ##     ##  ##   ##  ##          ##      #     ##     ## ##"
	@echo "\033[33;32m    ######   ########  ##     ## ##          ##            ##     ## ##"
	@echo "\033[33;32m    ##       ##   ##   ######### ##          ##            ##     ## ##"
	@echo "\033[33;32m    ##       ##    ##  ##     ## ##    ##    ##            ##     ## ##"
	@echo "\033[33;32m    ##       ##     ## ##     ##  ######     ##             #######  ########"
	@echo "\033[33;31m------------------------------------------------------------------------------"

help:
	@echo "\033[33;32m- make        \033[33;31m(Compile)"
	@echo "\033[33;32m- make fclean \033[33;31m(Destruction files .O and Program)"
	@echo "\033[33;32m- make clean  \033[33;31m(Destruction files .O)"
	@echo "\033[33;32m- make re     \033[33;31m(Recompile)"
	@echo "\033[33;32m- make name   \033[33;31m(Print the Program's Name)"

re: name fclean all

.PHONY: all fclean clean re name
