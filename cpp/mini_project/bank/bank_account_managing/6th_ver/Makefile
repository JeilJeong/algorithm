CC = g++
CFLAGS = -Wall -Wextra -Werror
INC_DIR = ./includes/
INC_FLAGS = -I $(INC_DIR)
SRC_LIST = main.cpp \
account.cpp \
normal_account.cpp \
high_credit_account.cpp \
account_handler.cpp
SRCS = $(addprefix ./srcs/, $(SRC_LIST))
OBJS = $(SRCS:.c=.o)
TARGET = bank

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INC_FLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	# rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

leak:
	valgrind --leak-check=full --error-limit=no ./$(TARGET)

.PHONY: all clean fclean re leak