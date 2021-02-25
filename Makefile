NAME = minishell

all: $(NAME)

LIBD = ./lib
LIB = $(addprefix lib/,cslib.a)
RM = rm -f
CC = clang
CFLAGS = -Wall -Wextra -g

SRCS = shell.c execute_cmd.c builtins.c
MAIN = main.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C $(LIBD)
	$(CC) $(MAIN) $^ -o $@ $(LIB)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@  $<

clean:
	$(RM) $(OBJS)
	make -C $(LIBD) clean

fclean:
	$(RM) $(OBJS) $(NAME)
	make -C $(LIBD) fclean

re: fclean all