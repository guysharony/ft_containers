# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 12:41:21 by gsharony          #+#    #+#              #
#    Updated: 2021/04/07 12:41:21 by gsharony         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS		= 	-Wall -Werror -Wextra -std=c++98

TESTS		=	tests/

FILES		= 	main.cpp \
				$(TESTS)list.cpp $(TESTS)vector.cpp $(TESTS)map.cpp $(TESTS)stack.cpp $(TESTS)queue.cpp

OBJS		= 	$(FILES:.cpp=.o)

EXE			= 	ft_containers

all:		$(EXE)

$(EXE):		$(OBJS)
			clang++ $(FLAGS) -o $(EXE) $(OBJS)

clean:
			rm $(OBJS)

fclean:		clean
			rm $(EXE)

re:			fclean all

.PHONY:		all clean fclean