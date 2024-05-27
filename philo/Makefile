# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 18:19:18 by fmaqdasi          #+#    #+#              #
#    Updated: 2024/05/27 20:04:25 by fmaqdasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := philo
CC          := cc
CFLAGS       := -Wall -Wextra -Werror
RM		    := rm -f

SRCS        := 				philo_action.c \
							philo_actionii.c \
							philo_checker.c \
							philo_init.c \
							philo_util.c \
							philo_util2.c \
							philo.c \
							                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	@${CC} ${CFLAGS} $(INCLUDE) -c $< -o $@
	
    
${NAME}:	${OBJS}
			@${CC} -pthread ${CFLAGS} ${OBJS} -o ${NAME} 
			@echo "\033[0;32mPHILO compiled successfully"



all:		${NAME}


clean:
			@${RM} *.o
			@echo "\033[0;31mObjects removed successfully"


fclean:		clean
			@${RM} ${NAME} 
			@echo "\033[0;31mAll created objects were removed successfully"

re:			fclean all
			@echo "\033[0;32mPHILO was recompiled successfully"


.PHONY:		all clean fclean re bonus