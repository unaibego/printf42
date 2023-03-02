# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 08:54:44 by ubegona           #+#    #+#              #
#    Updated: 2023/03/02 09:14:00 by ubegona          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(SRCS:.c=.o)
SRCS = ft_printf.c ft_printf_utils.c

AR = ar rcs libftprintf.a
GCCS = gcc -c -Wall -Werror -Wextra
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(OBJS)
	
%.o: %.c 
	$(GCCS) $<	
#$< gure leheneng dependentziaren izena da, kasu honetan %.c

clean: 
	rm -f *.o
fclean: clean 
	rm -f $(NAME) $(BOBJS)
re : fclean all

.PHONY: all clean fclean re
