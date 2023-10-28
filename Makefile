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
NAME	=	test_inf_int.out

SRCS	=	main.cpp inf_int.cpp
OBJS	=	$(SRCS:.cpp=.o)
HEAD	=	inf_int.h

CC		=	clang++
RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEAD)
	$(CC) $(OBJS) -include $(HEAD) -o $@

%.o		:	%.cpp
	$(CC) -c $^ -o $@

clean	:
	$(RM) $(OBJS)

fclean	:
	$(RM) $(OBJS)
	$(RM) $(NAME)

re		:
	make fclean
	make all

test	:
	make all
	make clean
	./$(NAME)

.PHONY	:	all clean fclean re test
