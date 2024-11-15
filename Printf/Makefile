NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =	ft_printf.c		\
	ft_lib_printf.c		\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)
	ar -rcs $(NAME) $(OBJ)

bonus : $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

rf : re
	@rm -f $(OBJ)
	@rm -f $(NAME)

s:
	ls -lh $(NAME)

.PHONY: all clean fclean re rf s
