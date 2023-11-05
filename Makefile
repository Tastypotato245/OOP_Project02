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

SRCS	=	main.cpp inf_int.cpp calculator.cpp
OBJS	=	$(SRCS:.cpp=.o)
C_SRCS	=	main.cpp inf_int_null.cpp calculator.cpp
C_OBJS	=	$(C_SRCS:.cpp=.o)
HEAD	=	inf_int.h

CC		=	c++
CFLAGS	=	-Wextra -Wall -Werror
RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEAD)
	$(CC) $(CFLAGS) $(OBJS) -include $(HEAD) -o $@

comp	:	$(C_NAME)

$(C_NAME)	:	$(C_OBJS) $(HEAD)
	$(CC) $(CFLAGS) $(C_OBJS) -include $(HEAD) -o $@

%.o		:	%.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

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
	/usr/bin/time ./$(NAME) 9999999999999999999999999999999999999999999999999999999999999999999999999 \* 9999999999999999999999999999999999999999999999999999999999999999
	/usr/bin/time ./$(C_NAME) 9999999999999999999999999999999999999999999999999999999999999999999999999 \* 9999999999999999999999999999999999999999999999999999999999999999
	make clean

.PHONY	:	all clean fclean re test comp ctest
