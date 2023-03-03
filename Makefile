# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoufid <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 22:06:48 by mmoufid           #+#    #+#              #
#    Updated: 2022/12/25 13:59:03 by mmoufid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

FILES = pipex.c utils1.c utils2.c utils3.c utils4.c utils5.c utils6.c

CC = gcc 

NAME = pipex.a

INCLUDEFILE = pipex.h

OBJFILES = ${FILES:.c=.o}

all : ${NAME}
	@cc -o pipex ${NAME}
	
${NAME} : ${OBJFILES} 
	@ar -rc ${NAME} ${OBJFILES} 

%.o:%.c $(INCLUDEFILE)
	@cc -c ${FLAGS} $< 

clean : 
	@rm -rf ${OBJFILES} ${BONUSO}
fclean : clean
	@rm -rf ${NAME}
re : fclean all