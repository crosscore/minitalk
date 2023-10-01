# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysakahar <ysakahar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 13:43:04 by ysakahar          #+#    #+#              #
#    Updated: 2023/02/09 13:43:05 by ysakahar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
SERVER_NAME = server
CLIENT_NAME_BONUS = client_bonus
SERVER_NAME_BONUS = server_bonus

SRCS = client.c server.c client_bonus.c server_bonus.c util.c
OBJS = $(SRCS:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): client.o util.o
	$(CC) $(FLAGS) $^ -o $@

$(SERVER_NAME): server.o util.o
	$(CC) $(FLAGS) $^ -o $@

bonus: $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)

$(CLIENT_NAME_BONUS): client_bonus.o util.o
	$(CC) $(FLAGS) $^ -o $@

$(SERVER_NAME_BONUS): server_bonus.o util.o
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re