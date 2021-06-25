CC = gcc
CFLAGS = -Wall -Wextra
INC_DIR = ./includes/
INCFLAGS = -I $(INC_DIR)
SRC_LIST = ft_main.c \
ft_solve.c \
ft_mem_utils.c \
ft_list_utils.c \
ft_string_utils.c \
ft_parse_utils.c \
ft_print_utils.c
SRCS = $(addprefix ./srcs/, $(SRC_LIST))
OBJS = $(SRCS:.c=.o)
TARGET = solve

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

leak:
	valgrind --leak-check=full --error-limit=no ./$(TARGET)

.PHONY: all clean fclean re leak