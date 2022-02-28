SRC = main.c ft_strjoin.c ft_strnstr.c ft_split.c ft_strncmp.c \
ft_strlen.c ft_strdup.c ft_substr.c utils.c
NAME = pipex
RM = rm -f
all : $(NAME)

$(NAME) : $(SRC)
	cc -c $(SRC)
	cc $(SRC) -o $(NAME)
clean :
	$(RM) *.o
fclean : clean
	$(RM) $(NAME)
re : fclean all
