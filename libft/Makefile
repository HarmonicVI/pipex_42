# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 20:46:46 by llornel           #+#    #+#              #
#    Updated: 2021/09/04 08:12:17 by llornel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	        = libft.a
SRC_PATH 		= src
GNL_PATH 		= gnl

SRCS			=	$(SRC_PATH)/ft_isspace.c \
            		$(SRC_PATH)/ft_isdigit.c \
            		$(SRC_PATH)/ft_bzero.c \
            		$(SRC_PATH)/ft_strdup.c \
            		$(SRC_PATH)/ft_strndup.c \
					$(SRC_PATH)/ft_memdel.c \
            		$(SRC_PATH)/ft_memset.c \
	           		$(SRC_PATH)/ft_memcpy.c \
 					$(SRC_PATH)/ft_strlen.c \
 					$(SRC_PATH)/ft_strlcpy.c \
 					$(SRC_PATH)/ft_strlcat.c \
 					$(SRC_PATH)/ft_strcpy.c \
 					$(SRC_PATH)/ft_strcat.c \
 					$(SRC_PATH)/ft_strncpy.c \
 					$(SRC_PATH)/ft_strncat.c \
					$(SRC_PATH)/ft_substr.c \
					$(SRC_PATH)/ft_strjoin.c \
					$(SRC_PATH)/ft_strstr.c \
					$(SRC_PATH)/ft_strnstr.c \
					$(SRC_PATH)/ft_strdel.c \
					$(SRC_PATH)/ft_split.c \
					$(SRC_PATH)/ft_strchr.c \
					$(SRC_PATH)/ft_strrchr.c \
					$(SRC_PATH)/ft_strcmp.c \
					$(SRC_PATH)/ft_strncmp.c \
					$(SRC_PATH)/ft_atoi.c \
					$(SRC_PATH)/ft_putchar_fd.c \
					$(SRC_PATH)/ft_putnbr_fd.c \
					$(SRC_PATH)/ft_putstr_fd.c \
					$(SRC_PATH)/ft_putendl_fd.c \
					$(GNL_PATH)/get_next_line_utils.c \
					$(GNL_PATH)/get_next_line.c
			
OBJS	= $(SRCS:.c=.o)

HEADER 			= -I./includes/libft.h -I./includes/get_next_line.h
LIBC 			= ar rc
LIBR 			= ranlib

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

.c.o:		
			${CC} ${CFLAGS} $(HEADER) -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${LIBC} ${NAME} ${OBJS}
			${LIBR} ${NAME}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}	

re:			fclean all

.PHONY: 	all clean fclean re .c.o
