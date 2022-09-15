# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 15:01:46 by ntanjaou          #+#    #+#              #
#    Updated: 2022/09/15 15:01:49 by ntanjaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

HEADER = header.h

SRC = 	main.c \
		utils.c \
		utils2.c \
		initialize.c \
		launch.c \
		eat.c \

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -g -pthread $(OBJ) -o $(NAME)

clean : 
	@rm -f $(OBJ)

fclean : clean 
	@rm -rf $(NAME)

re : fclean all