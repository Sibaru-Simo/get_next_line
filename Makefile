CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = gnl.a

SRCS = get_next_line_utils.c get_next_line.c

OBJ = $(SRCS:.c=.o)

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
re: fclean all
