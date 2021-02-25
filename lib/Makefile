NAME = cslib.a

all: $(NAME)

RM = rm -f
CC = clang
CFLAGS = -Wall -Wextra -g
SRCS = 	strchr.c		strcpy.c		strcmp.c		bzero.c         isalnum.c       islower.c       isspace.c       main.c          puts.c          strjoin.c       strnew.c        toupper.c \
		get_next_line.c isalpha.c       isoctal.c       isupper.c       memalloc.c      readline.c      strlen.c        strtok.c \
		hexvalue.c      isdigit.c       isprint.c       isxdigit.c      memset.c        strdup.c        strncmp.c       tolower.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar -r $@ $^
	ranlib $@

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@  $<

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re: clean all
