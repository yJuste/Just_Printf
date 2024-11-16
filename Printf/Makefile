NAME = libftprintf

CC = gcc

SRC =	ft_printf.c		\
	ft_printf_2.c		\
	ft_print_percent.c	\
	ft_print_c.c		\
	ft_printf_lib.c		\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

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
