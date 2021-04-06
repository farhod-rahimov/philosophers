# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: farhod <farhod@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/06 16:30:33 by btammara          #+#    #+#              #
#    Updated: 2021/04/06 11:45:59 by farhod           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			./main.c \
				./ft_check_death_phil.c \
				./ft_monitor.c \
				./ft_print.c \
				./ft_work_in_thread.c \
				./ft_get_data.c \
				./mini_libft/ft_atoi.c \
				./mini_libft/ft_bzero.c \
				./mini_libft/ft_putnbr_fd.c \
				./mini_libft/ft_putstr_fd.c \
				./mini_libft/ft_strlen.c

OBJS =			$(SRCS:.c=.o)

GCC = 			gcc

FLAGS =			-Wall -Wextra -Werror

NAME =			philo_three

%.o:			%.c
				@ $(GCC) -c $(FLAGS) $< -o $(<:.c=.o)

all: 			$(NAME)

$(NAME):		$(OBJS)
				@ $(GCC) -o $(NAME) $(OBJS)
				@ echo 'philo_three built, run ./philo_three'

clean:
				@ rm -f $(OBJS)

fclean:			clean
				@ rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re