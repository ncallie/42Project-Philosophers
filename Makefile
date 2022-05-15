# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncallie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 17:23:14 by ncallie           #+#    #+#              #
#    Updated: 2022/01/11 14:35:56 by ncallie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re help
CC = gcc
NAME=philo
FLAGS = -Wall -Wextra -Werror -c
SRCS=	argv.c dead.c error_and_free.c \
		init_mutex_philo.c philo_thread.c \
		philo.c routine.c utils.c
OBJ=$(SRCS:.c=.o)

GREEN = \033[0;32m
RESET = \033[0m
BLUE = \033[0;44m
RED = \033[0;31m
YELLOW = \033[0;33m

all: $(SRCS) $(NAME)
	@echo "$(GREEN)Done$(RESET)"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $@
	@echo "$(RED)Create philo$(RESET)"
	@sleep 1s
	@clear

.c.o:
	@$(CC) $(FLAGS) $< -o $@
	@echo "$(BLUE)Create object$(RESET) - $(GREEN)$@ $(RESET)"

clean:
	@rm -rf $(OBJ)
	@echo "$(YELLOW)Delete objects$(RESET)"
	@sleep 1s
	@clear

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Delete push_swap$(RESET)"
	@sleep 1s
	@clear
re: fclean all

help: 
	@echo "all clean fclean re "
	