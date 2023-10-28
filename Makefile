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
C_NAME	=	inf_int_null

SRCS	=	main.cpp inf_int.cpp
OBJS	=	$(SRCS:.cpp=.o)
C_SRCS	=	main.cpp inf_int_null.cpp
C_OBJS	=	$(C_SRCS:.cpp=.o)
HEAD	=	inf_int.h

CC		=	clang++
RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEAD)
	$(CC) $(OBJS) -include $(HEAD) -o $@

comp	:	$(C_NAME)

$(C_NAME)	:	$(C_OBJS) $(HEAD)
	$(CC) $(C_OBJS) -include $(HEAD) -o $@

%.o		:	%.cpp
	$(CC) -c $^ -o $@

clean	:
	$(RM) $(OBJS)
	$(RM) $(C_OBJS)

fclean	:
	make clean
	$(RM) $(NAME)
	$(RM) $(C_NAME)

re		:
	make fclean
	make all

test	:
	make all
	make clean
	./$(NAME)

ctest	:
	make all
	make comp
	time ./$(NAME) 1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111 \* 1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
	time ./$(C_NAME) 1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111 \* 1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
	make clean

.PHONY	:	all clean fclean re test comp ctest
