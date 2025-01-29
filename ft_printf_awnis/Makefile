# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adichou <adichou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 01:54:19 by adichou           #+#    #+#              #
#    Updated: 2025/01/28 18:48:44 by adichou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# Nom de l'exécutable
NAME = libftprintf.a

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Fichiers source
SRCS = ft_printf.c \
		printfunctions.c \
		printfunctions2.c \
		printfunctions3.c

# Fichiers objets
OBJ = $(SRCS:.c=.o)

# Règle par défaut
all: $(NAME)

# Création de l'archive statique
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Compilation des fichiers .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean les fichiers objets
clean:
	rm -f $(OBJ)

# Supprimer les fichiers objets et l'exécutable
fclean: clean
	rm -f $(NAME)

# Refaire tout
re: fclean all

.PHONY: all clean fclean re
