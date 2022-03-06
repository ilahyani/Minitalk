SRCS_svr =	server.c\
				utils.c

SRCS_clt =	client.c\
				utils.c

BNS_svr =	bonus/server_bonus.c\
				bonus/utils_bonus.c

BNS_clt =	bonus/client_bonus.c\
				bonus/utils_bonus.c

OBJS_srv = $(SRCS_svr:.c=.o)

OBJS_clt = $(SRCS_clt:.c=.o)

BNS_OBJS_srv = $(BNS_svr:.c=.o)

BNS_OBJS_clt = $(BNS_clt:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

PRNTF = ./ft_printf

LBFT_PRNTF = ./ft_printf/libftprintf.a	

all:	$(OBJS_clt) $(OBJS_srv) $(LBFT_PRNTF)
			$(CC) $(CFLAGS) $(OBJS_clt) $(LBFT_PRNTF) -o client
			$(CC) $(CFLAGS) $(OBJS_srv) $(LBFT_PRNTF) -o server

bonus:	$(BNS_OBJS_srv) $(BNS_OBJS_clt) $(LBFT_PRNTF)
			$(CC) $(CFLAGS) $(BNS_OBJS_srv) $(LBFT_PRNTF) -o bonus_server
			$(CC) $(CFLAGS) $(BNS_OBJS_clt) $(LBFT_PRNTF) -o bonus_client

$(LBFT_PRNTF):
				Make -C $(PRNTF)

clean:	
		$(RM) $(OBJS_srv) $(OBJS_clt) $(BNS_OBJS_srv) $(BNS_OBJS_clt) $(PRNTF)/*.o 

fclean: clean
		$(RM) client server $(LBFT_PRNTF) bonus_server bonus_client

re:	fclean all