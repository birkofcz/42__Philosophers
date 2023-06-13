# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 15:29:04 by sbenes            #+#    #+#              #
#    Updated: 2023/06/12 14:16:51 by sbenes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#color and formatting definitions:
BOLD =		\033[1m
GREEN =		\033[32m
RED =		\033[31m
YELONBLK = 	\033[1;93;40m
NC =		\033[0m

#name
NAME = 		philo

# compiler
CC =		cc
CFLAGS =	-Wall -Wextra -Werror

#Includes
INC = -I philosophers.h
	
#sources
SRC = 	main.c args.c utils.c utils_time.c error.c init.c routine.c actions.c
OBJ =		$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BOLD)$(GREEN)[ 🙊 Compiling together... ]$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INC)
	@echo "$(BOLD)$(GREEN)[ 🪄 Program ready! ]$(NC)"
	@echo ""
	@echo "$(YELONBLK)$(BOLD)                                                         $(NC)"
	@echo "$(YELONBLK)$(BOLD)  ______ _     _ _                 _                     $(NC)"
	@echo "$(YELONBLK)$(BOLD)  | ___ \ |   (_) |               | |                    $(NC)"
	@echo "$(YELONBLK)$(BOLD)  | |_/ / |__  _| | ___  ___ _ __ | |__   ___ _ __ ___   $(NC)"
	@echo "$(YELONBLK)$(BOLD)  |  __/| '_ \| | |/ _ \/ __| '_ \| '_ \ / _ \ '__/ __|  $(NC)"
	@echo "$(YELONBLK)$(BOLD)  | |   | | | | | | (_) \__ \ |_| | | | |  __/ |  \__ \  $(NC)"
	@echo "$(YELONBLK)$(BOLD)  \_|   |_| |_|_|_|\___/|___/ .__/|_| |_|\___|_|  |___/  $(NC)"
	@echo "$(YELONBLK)$(BOLD)                            | |                          $(NC)"
	@echo "$(YELONBLK)$(BOLD)                            |_| ...wanna spaghetti?🍝💀  $(NC)"
	@echo "$(YELONBLK)$(BOLD)                                                         $(NC)"

	@echo ""

$(OBJ): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

bonus: all

clean:
	@echo "$(BOLD)$(RED)[ 🔥 Purging object files ]$(NC)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(BOLD)$(RED)[ 🔥 Removing program ]$(NC)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean


 
