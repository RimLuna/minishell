NAME	=	minishell

SRCS	=

all		:	$(NAME)

$(NAME)	:	$(SRCS)
			gcc $(FLAGS) $(SRCS) -o $(NAME)

clean	:
			rm -rf $(SRCS:.c=.o)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all