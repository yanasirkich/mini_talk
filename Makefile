# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 14:00:26 by ysirkich          #+#    #+#              #
#    Updated: 2024/11/09 04:46:50 by ysirkich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
NAME = mini_talk
SERVER = server
CLIENT = client
CC = gcc
CFLAGS = -Wall	-Wextra	-Werror -g
INCLUDE	=-I. -Ilibft

# Libraries
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBS = -L$(LIBFT_DIR)	-lft

# Rues 
.c.o:
	@echo "Compiling $<..."
	@$(CC)	$(CFLAGS)	$(INCLUDE)	-c	$<	-o	$@

$(NAME):	$(SERVER)	$(CLIENT)
			@echo "Linking stuff..."
			@echo "$(NAME) created successfully!"
			
#  Targets for server and client
$(SERVER): server.o $(LIBFT)
	@echo "Building server..."
	@$(CC) $(CFLAGS) server.o $(LIBS) -o $(SERVER)
	@echo "$(SERVER) created successfully!"

$(CLIENT): client.o $(LIBFT)
	@echo "Building client..."
	@$(CC) $(CFLAGS) client.o $(LIBS) -o $(CLIENT)
	@echo "$(CLIENT) created successfully!"

# server.o: server.c minitalk.h check without it and comment out if it doesnt work
# client.o: client.c minitalk.h

# Building libft
$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)

# Cleaning object files and executables
clean:
	@echo "Cleaning object files..."
	@$(RM) *.o
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Removing executables..."
	@ rm -rf $(SERVER) $(CLIENT)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re