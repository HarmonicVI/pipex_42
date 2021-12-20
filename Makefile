# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/07 10:53:36 by llornel           #+#    #+#              #
#    Updated: 2021/09/04 21:40:07 by llornel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex

LIBFT_PATH		= libft
LIBFT 			= $(LIBFT_PATH)/libft.a
LIBFT_MAKE		= ${MAKE} -C ${LIBFT_PATH}

SRC_PATH 		= src

CMN 			= $(SRC_PATH)/ft_error.c \
				  $(SRC_PATH)/ft_execute.c \
				  $(SRC_PATH)/ft_file.c \
				  $(SRC_PATH)/ft_path.c 

SRCS			= $(SRC_PATH)/ft_pipex.c \
				  pipex.c
			
BONUS_SRCS		= $(SRC_PATH)/ft_pipex_bonus.c \
				  pipex_bonus.c

CMN_OBJS		= $(CMN:.c=.o)
OBJS			= $(SRCS:.c=.o)
BONUS_OBJS		= $(BONUS_SRCS:.c=.o)

CC				= gcc
HEADER 			= -I./includes/pipex.h
BONUS_HEADER	= -I./includes/pipex_bonus.h
CFLAGS			= -Wall -Wextra -Werror
DFLAGS 			= -g -fsanitize=address
RM				= rm -f

%.o:			%.c $(HEADER) Makefile 
				${CC} $(CFLAGS) -c -I $(HEADER) $< -o $(<:.c=.o) 
# .c.o:		
# 				${CC} ${CFLAGS} -I $(HEADER) -c $< -o ${<:.c=.o}
			
${NAME}:		${CMN_OBJS} ${OBJS} 
				${RM} ${BONUS_OBJS}
				${MAKE} -C ${LIBFT_PATH}
				${CC} ${CFLAGS} ${CMN_OBJS} ${OBJS} $(HEADER) ${LIBFT} -o ${NAME}

all:			${NAME}

clean:		
				$(LIBFT_MAKE) clean
				${RM} ${CMN_OBJS} ${OBJS} $(BONUS_OBJS)

fclean:			clean
				$(LIBFT_MAKE) fclean
				${RM} ${NAME}	

re:				fclean all

bonus:			${CMN_OBJS} $(BONUS_OBJS)
				${RM} ${OBJS}
				${MAKE} -C ${LIBFT_PATH}
				${CC} ${CFLAGS} ${CMN_OBJS} $(BONUS_OBJS) $(BONUS_HEADER) ${LIBFT} -o ${NAME}
				
.PHONY: 		all clean fclean re bonus norm
