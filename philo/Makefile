# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 17:31:20 by pruenrua          #+#    #+#              #
#    Updated: 2023/09/26 22:17:09 by pruenrua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra

THREAD_F = -lpthread

SRC = util.c monitor.c routine.c init.c free.c main.c

OBJ = ${SRC:.c=.o}
all = ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${THREAD_F} ${OBJ} -o ${NAME}

clean :
	rm -rf ${OBJ}

fclean : clean 
	rm -rf ${NAME}

re : fclean ${NAME}

.PHONY : all clean re fclean
