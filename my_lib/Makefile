##
## Makefile for  in /home/walbec_h/rendu 2014-2015/Igraph/MUL_2014_rtv1/my_lib
## 
## Made by hugo walbecq
## Login   <walbec_h@epitech.net>
## 
## Started on  Mon Feb  2 13:28:00 2015 hugo walbecq
## Last update Mon Feb  2 13:28:10 2015 hugo walbecq
##

NAME		=	libmy.a

SRC		=	my_getnbr.c		\
			my_strstr.c		\
			my_putchar.c		\
			my_put_nbr.c		\
			my_putstr.c		\
			my_revstr.c		\
			my_strlen.c		\

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)
			cp my.h ../include

clean		:	
			rm -rf $(OBJ)

fclean		:	clean
			rm $(NAME)

re		:	fclean all
