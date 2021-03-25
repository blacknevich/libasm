NAME		= libasm.a
#####################################sources#######################################
SRC			= ft_strlen.s\
			  ft_strcpy.s\
			  ft_write.s\
			  ft_read.s\
			  ft_strdup.s\
			  ft_strcmp.s
#####i################################objects#######################################
OBJ			= $(SRC:.s=.o)
#####################################flags#######################################
CFLAGS		= -Wall -Wextra -Werror
NFLAGS		= -f macho64
SANITIZE	= -fsanitize=address

.s.o: $(SRC)
	nasm $(NFLAGS) $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -rf $(OBJ) 

fclean: clean
	rm -rf test
	rm -rf $(NAME)

test: $(NAME) main.c
	gcc $(CFLAGS) -L. -lasm -o test main.c
	./test

re: fclean all

.PHONY: all clean fclean re
