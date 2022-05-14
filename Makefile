SRCS			=	./srcs/push_swap.c ./srcs/moves.c ./srcs/sorting.c

OBJS			= 	$(SRCS:.c=.o)

LIBS			= 	./srcs/libftprintf.a

CC				= 	gcc
RM				= 	rm -f
CFLAGS			= 	-Wall -Wextra -Werror -I./incs

NAME			= 	push_swap

all:			$(NAME)

$(NAME):		$(OBJS)
				gcc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
				$(RM) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(OBJS)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
