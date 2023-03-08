NAME = ft_containers


CC = c++ 

CPPFLAGS = -std=c++98  -Wall -Wextra -Werror -fsanitize=address -g

SRCS =	tests/main.cpp \
		tests/map_tests.cpp \
		tests/set_tests.cpp \
		tests/stack_tests.cpp \
		tests/vector_tests.cpp

OBJS:=$(SRCS:.cpp=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	$(CC)   $(CPPFLAGS) $(OBJS)  -o $(NAME)


clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : clean all