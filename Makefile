NAME				= ft_select
SRC                 = src/ft_select.c \
					  src/t_arg_handling.c \
					  src/process_command.c \
					  src/ft_move.c 

LIB 				= libft/libft.a
CC                  = clang

.PHONY = all

all:
	@make --directory libft
	@echo "\033[32mft_select compiling...\033[0m"
	@$(CC) -I inc $(SRC) $(LIB)  -o ft_select -ltermcap
	@echo "\033[33mCompiled!\033[0m"


clean:

fclean:
	@rm -f ft_select
