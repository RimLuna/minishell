NAME = minishell

LFD = ./libft
LFF = -Wextra
LFL = libft/libft.a
CC = clang

CFILES   = $(wildcard *.c)
OBJFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJFILES)
	@make -C $(LFD)
	$(CC) -o $@ $^ $(LFL)

%.o: %.c
	$(CC) -c -o $@ $^

clean:
	rm $(OBJFILES)
	@make clean -C $(LFD)

fclean: clean
	rm -f $(NAME)
	@make -C fclean $(LFD)

re: fclean all 