# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 15:56:05 by kyusulee          #+#    #+#              #
#    Updated: 2023/10/28 16:37:52 by kyusulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	inf_int

SRCS	=	main.cpp inf_int.cpp calculator.cpp
OBJS	=	$(SRCS:.cpp=.o)
HEAD	=	inf_int.h

CC		=	c++
CFLAGS	=	-Wextra -Wall -Werror
RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEAD)
	$(CC) $(CFLAGS) $(OBJS) -include $(HEAD) -o $@

%.o		:	%.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean	:
	$(RM) $(OBJS)

fclean	:
	make clean
	$(RM) $(NAME)

re		:
	make fclean
	make all

test	:
	make all
	make clean
	./$(NAME)

.PHONY	:	all clean fclean re test
