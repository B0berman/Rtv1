##
## Makefile for  in /home/walbec_h/rendu 2014-2015/Igraph/MUL_2014_rtv1
## 
## Made by hugo walbecq
## Login   <walbec_h@epitech.net>
## 
## Started on  Mon Feb  2 13:25:04 2015 hugo walbecq
## Last update Fri Apr 17 12:26:38 2015 walbec_h
##

NAME		=	rtv1

MAIN		=	main.c

SRC		=	$(MAIN)\
			error_obj.c\
			reflexion.c\
			aliasing.c\
			shadow.c\
			key_expose.c\
			move.c\
			light.c\
			intersection.c\
			delta.c\
			situation.c\
			find.c\
			my_pixel_put_to_image.c

OBJ		=	$(SRC:.c=.o)

LIBFLAGS	=	-L my_lib/ \
			-lmy

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			cc -o $(NAME) $(OBJ) -L./minilibx/ -lmlx_x86_64 -L/usr/lib64/X11 -lXext -lX11 -lm -L. my_lib/libmy.a

lib		:
			make re -C my_lib/

clean		:
			rm -fr $(OBJ)
			make clean -C my_lib/

fclean		:	clean
			rm -fr $(NAME)

re		:	lib fclean all
