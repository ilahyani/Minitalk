# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilahyani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 17:05:03 by ilahyani          #+#    #+#              #
#    Updated: 2021/12/18 17:14:39 by ilahyani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS        =   ft_printf.c\
                ft_printf_utils.c

OBJS		= 	$(SRCS:.c=.o)

NAME		= 	libftprintf.a

CC 			=	gcc

CFLAGS		= 	-Wall -Wextra -Werror

RM			= 	rm -rf

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
