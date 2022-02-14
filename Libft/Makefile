# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 14:54:50 by ijmari            #+#    #+#              #
#    Updated: 2021/11/11 15:58:36 by ijmari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_calloc.c  ft_isdigit.c ft_memcpy.c ft_memmove.c ft_strlcat.c ft_strnstr.c \
ft_isalnum.c ft_isprint.c ft_memmove.c ft_strlcpy.c ft_strrchr.c \
ft_atoi.c ft_isalpha.c ft_memchr.c  ft_memset.c  ft_strlen.c  ft_tolower.c \
ft_bzero.c ft_isascii.c ft_memcmp.c  ft_strdup.c  ft_strncmp.c ft_toupper.c \
ft_split.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strchr.c
BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJ = $(SRC:.c=.o)
B_OBJ = $(BONUS:.c=.o)
HEADER = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)
clean :
	$(RM) $(OBJ)
	$(RM) $(B_OBJ)
fclean : clean
	$(RM) $(NAME)
re : fclean all bonus run
bonus : $(B_OBJ)
	ar rcs $(NAME) $(B_OBJ)
.PHONY : all clean fclean re
run: all
	gcc  main.c libft.a
