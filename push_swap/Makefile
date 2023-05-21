CHECKER = checker
PUSH_SWAP = push_swap
LIB = ./libft/libft.a
CC = cc
# CFLAGS = -Wall -Wextra -Werror

SRC =	check_input.c \
		print_error.c main.c ./tools/tools.c\
		./tools/tools2d.c sort.c ./tools/moves.c \
		./tools/sort_three.c ./tools/fourth_fifth.c


OBJ = $(SRC:.c=.o)

all: $(PUSH_SWAP)

$(PUSH_SWAP): $(OBJ) 
	make all -C ./libft
	gcc $(OBJ) ${LIB} -o $(PUSH_SWAP)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	make clean -C ./libft 
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf $(PUSH_SWAP)

re: fclean all