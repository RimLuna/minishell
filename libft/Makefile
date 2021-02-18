NAME = libft.a

CC = clang

CFILES   = $(wildcard *.c)
OBJFILES = $(CFILES:.c=.o)

FLAGS =		-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJFILES)
	$(CC) -c $^ 
	ar -r  $(NAME) $(OBJFILES)
	ranlib $(NAME)

%.o: %.c
	$(CC) -c -o $@ $^

clean:
	rm $(OBJFILES)

fclean:
	rm $(NAME) $(OBJFILES)

re: fclean all