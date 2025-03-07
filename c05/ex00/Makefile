# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 10:47:57 by snegi             #+#    #+#              #
#    Updated: 2024/08/28 10:47:59 by snegi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS	=	main.cpp Bureaucrat.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	Bureaucrat

all:		$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
