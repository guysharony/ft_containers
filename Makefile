# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 12:41:21 by gsharony          #+#    #+#              #
#    Updated: 2021/04/14 06:29:50 by gsharony         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX							=	clang++

NAME						=	ft_containers

FLAGS						=	-Wall -Wextra -Werror --std=c++98

INCLUDES_DIRECTORY			=	./include/

OBJECTS_DIRECTORY 			=	./objects/

SOURCES_DIRECTORY			=	./tests/

SOURCES_FILES				=	main.cpp \
								list.cpp \
								map.cpp \
								queue.cpp \
								stack.cpp \
								vector.cpp \

OBJECTS						= 	$(addprefix $(OBJECTS_DIRECTORY),$(SOURCES_FILES:.cpp=.o));


$(OBJECTS_DIRECTORY)%.o: 	$(SOURCES_DIRECTORY)%.cpp
							@mkdir -p $(OBJECTS_DIRECTORY)
							@$(CXX) $(FLAGS) -I $(INCLUDES_DIRECTORY) -c -o $@ $<

$(NAME):					$(OBJECTS)
							@$(CXX) $(FLAGS) -o $(NAME) $(OBJECTS)

all: 						$(NAME)

clean:
							@rm -rf $(OBJECTS_DIRECTORY)

fclean: 					clean
							@rm -f $(NAME)

re: 						fclean all

.PHONY: 					temporary, norme, clean