NAME = Harl
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRCS = main.cpp Harl.cpp
# SRCS = $(addprefix $(DIR)/,$(SRCS_RAW))
OBJS = $(SRCS:c=o)
# DIR = srcs

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean :
	rm -rf $(NAME)
re: clean all