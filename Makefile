CC    := g++

RM    := rm -rf

LDFLAGS    += -lssh

SRCS    := $(shell find src -type f -name "*.cpp")

OBJS    := $(SRCS:.cpp=.o)

NAME    := spatch

all: $(NAME)

$(NAME): $(OBJS)
	    $(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	    $(RM) $(OBJS)

fclean: clean
	    $(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
