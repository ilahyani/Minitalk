# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 17:37:07 by ilahyani          #+#    #+#              #
#    Updated: 2022/03/06 18:30:11 by ilahyani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./utils.c

OBJS = $(SRCS:.c=.o)

BNS_SRCS = bonus/utils_bonus.c

BNS_OBJS = $(BNS_SRCS:.c=.o)

NAME1 = server

NAME2 = client

BNS_NAME1 = server_bonus

BNS_NAME2 = client_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

PRNTF = ./ft_printf

HDR = ./minitalk.h

BNS_HDR = ./bonus/minitalk_bonus.h

LBFT_PRNTF = ./ft_printf/libftprintf.a

all:	$(NAME1) $(NAME2)

$(NAME1): $(OBJS) $(LBFT_PRNTF)
			$(CC) $(CFLAGS) server.c $(OBJS) $(LBFT_PRNTF)  -o $(NAME1)
$(NAME2): $(OBJS) $(LBFT_PRNTF)
			$(CC) $(CFLAGS) client.c $(OBJS) $(LBFT_PRNTF)  -o $(NAME2)

bonus:	$(BNS_NAME1) $(BNS_NAME2)

$(BNS_NAME1): $(BNS_OBJS) $(LBFT_PRNTF)
				$(CC) $(CFLAGS) bonus/server_bonus.c $(BNS_OBJS) $(LBFT_PRNTF) -o $(BNS_NAME1)
$(BNS_NAME2): $(BNS_OBJS) $(LBFT_PRNTF)
				$(CC) $(CFLAGS) bonus/client_bonus.c $(BNS_OBJS) $(LBFT_PRNTF) -o $(BNS_NAME2)

$(LBFT_PRNTF):
				Make -C $(PRNTF)

%.o: %.c $(HDR) $(BNS_HDR)
			$(CC) $(CFLAGS) -c $< -o $@

clean:	
		$(RM) $(OBJS) $(BNS_OBJS) $(PRNTF)/*.o 

fclean: clean
		$(RM) client server $(LBFT_PRNTF) server_bonus client_bonus

re:	fclean all