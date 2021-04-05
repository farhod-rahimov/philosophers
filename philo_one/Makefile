# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: farhod <farhod@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/06 16:30:33 by btammara          #+#    #+#              #
#    Updated: 2021/04/05 17:34:20 by farhod           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			./main.c \
				./ft_monitor.c \
				./ft_work_in_thread.c \
				./ft_check_death_phil.c \
				./ft_print.c

OBJS =			$(SRCS:.c=.o)

GCC = 			gcc

FLAGS =			-Wall -Wextra -Werror

NAME =			philo_one

%.o:			%.c
				@ $(GCC) -c $(FLAGS) $< -o $(<:.c=.o)

all: 			$(NAME)

$(NAME):		$(OBJS)
				@ $(GCC) -o $(NAME) $(OBJS) libft.a
				@ echo 'philo_one built, run ./philo_one'

clean:
				@ rm -f $(OBJS)

fclean:			clean
				@ rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re