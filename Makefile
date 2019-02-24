NAME				= ft_select
SRC                 = src/ft_select.c
CC                  = clang

.PHONY = all

all:
	@echo "\033[32mft_select compiling...\033[0m"
	@$(CC) -I inc $(SRC) -o ft_select -ltermcap
	@echo "\033[33mCompiled!\033[0m"


clean:

fclean:
	@rm -f ft_select