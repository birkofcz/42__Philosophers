# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 15:29:04 by sbenes            #+#    #+#              #
#    Updated: 2023/05/30 12:00:18 by sbenes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#color and formatting definitions:
BOLD =	\033[1m
GREEN =	\033[32m
RED =	\033[31m
NC =	\033[0m

#name
NAME = 		philo

# compiler
CC =		cc
CFLAGS =	-Wall -Wextra -Werror

#Includes
INC = -I philosophers.h
	
#sources
SRC = 	main.c init_args.c utils.c error.c utils_time.c routine.c actions.c

#objects
OBJ =		$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BOLD)$(GREEN)[ 🙊 Compiling together... ]$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INC)
	@echo "$(BOLD)$(GREEN)[ 🪄 Program ready! ]$(NC)"
	@echo ""
	@echo "$(BOLD)[ -- Welcome to Philosophers -- ]$(NC)"
	@echo ""
	@echo "$(BOLD)run ./philo <n_of_philos> <time_to_die> <time_to_eat> <time_to_sleep> <opt:n_of_meals_each_philo_needs_to_eat>$(NC)"
	@echo ""
	@echo "[ -- Have fun ! 😉 -- ]"
	@echo ""

$(OBJ): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

bonus: all

clean:
	@echo "$(BOLD)$(RED)[ 🔥 Purging object files ]$(NC)"
	@rm -f $(OBJ)

fclean:
	@echo "$(BOLD)$(RED)[ 🔥 Removing program ]$(NC)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean


 
