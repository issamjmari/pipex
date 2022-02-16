SRC = main.c ft_strjoin.c ft_strnstr.c ft_split.c ft_strncmp.c \
ft_strlen.c ft_strdup.c error.c libft.a
NAME = pipex
RM = rm -f
all : $(NAME)

$(NAME) : $(SRC)
	cc $(SRC) -o $(NAME)
clean :
fclean : clean
	$(RM) $(NAME)
re : fclean all
