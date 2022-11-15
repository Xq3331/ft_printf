# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 09:41:56 by pfaria-d          #+#    #+#              #
#    Updated: 2022/11/15 16:35:44 by pfaria-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_pow.c ft_power_base.c ft_putddnbr_fd.c ft_printf.c ft_putchar_fd.c ft_putdnbr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putunbr_fd.c ft_strlen.c

SRCBONUS = 

OBJS = $(SRC:.c=.o)

OBJSBONUS = $(SRCBONUS:.c=.o)

GCC = gcc -Wall -Werror -Wextra

RM  = rm -f

NAME = libftprintf.a

ifdef MAKEBONUS
    OBJS = $(OBJSBONUS)
endif

all: $(NAME)

.c.o:
	$(GCC) -I ./ -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus:
			@make MAKEBONUS=1 all

clean:
			$(RM) $(OBJS) $(OBJSBONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME) 
			
.PHONY: all clean fclean re bonus

