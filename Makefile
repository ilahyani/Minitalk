SRCS_svr	=	server.c\
				utils.c

SRCS_clt	=	client.c\
				utils.c

BNS_svr	=	bonus/server.c\
			bonus/utils.c

BNS_clt	=	bonus/client.c\
			bonus/utils.c

OBJS_srv	= 	$(SRCS_svr:.c=.o)

OBJS_clt	= 	$(SRCS_clt:.c=.o)

BNS_OBJS_srv	= 	$(BNS_svr:.c=.o)

BNS_OBJS_clt	= 	$(BNS_clt:.c=.o)

S_NAME = server

C_NAME = client

BNS_S_NAME = bonus_server

BNS_C_NAME = bonus_client

CC	=	gcc

CFLAGS	= -Wall -Wextra -Werror

RM = rm -rf

PRNTF = ./ft_printf

LBFT_PRNTF = ./ft_printf/libftprintf.a

$(S_NAME):	$(OBJS_srv) $(LBFT_PRNTF)
			$(CC) $(CFLAGS) $(OBJS_srv) $(LBFT_PRNTF) -o $(S_NAME)

$(C_NAME):	$(OBJS_clt) $(LBFT_PRNTF)
			$(CC) $(CFLAGS) $(OBJS_clt) $(LBFT_PRNTF) -o $(C_NAME)

all:	$(S_NAME) $(C_NAME)

$(BNS_S_NAME):	$(BNS_OBJS_srv) $(LBFT_PRNTF)
			$(CC) $(CFLAGS) $(BNS_OBJS_srv) $(LBFT_PRNTF) -o $(BNS_S_NAME)

$(BNS_C_NAME):	$(BNS_OBJS_clt) $(LBFT_PRNTF)
			$(CC) $(CFLAGS) $(BNS_OBJS_clt) $(LBFT_PRNTF) -o $(BNS_C_NAME)

bonus:	$(BNS_S_NAME) $(BNS_C_NAME)

$(LBFT_PRNTF):
				make -C $(PRNTF)

clean:	
		$(RM) $(OBJS_srv) $(OBJS_clt) $(BNS_OBJS_srv) $(BNS_OBJS_clt) $(PRNTF)/*.o 

fclean: clean
		$(RM) $(S_NAME) $(C_NAME) $(LBFT_PRNTF) $(S_bonus) $(C_bonus)

re:	fclean all