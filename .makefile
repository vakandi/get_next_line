GCCFLAG=-Wall -Wextra -Werror
all:
	@./imcat 42.jpg
	@sleep 1s
	@clear
	gcc $(GCCFLAG) get_next_line.c get_next_line_utils.c -o get_next_line
	@echo "\033[1;32m - COMPILATION FINISHED -\n\n\033[0m"
	@echo "\033[1;34m  Name of the executable: \n\033[1;34m           get_next_line\n\n\033[0m"
clean:
	@/bin/rm *.o
	@/bin/rm -f *.gch

fclean: clean
	@/bin/rm -f get_next_line

re: fclean all

