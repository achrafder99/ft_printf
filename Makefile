# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 22:35:30 by adardour          #+#    #+#              #
#    Updated: 2022/11/09 13:02:50 by adardour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra 
AR = ar rcs
RM = rm -rf
NAME = libftprintf.a
header = libftprintf.h

SOURCE = ft_printf.c function_helper.c ft_putchar.c ft_puts.c ft_putnbr.c putnbr_base_16.c \
ft_strlen.c ft_calloc.c ft_bzero.c
OBJS = ${SOURCE:%.c=%.o}

all:${NAME}

%.o:%.c ${header}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:${OBJS} ${SOURCE}
	${AR} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}


fclean:clean 
	${RM} ${NAME}

re: fclean all
