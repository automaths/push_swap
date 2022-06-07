SRCS			=	./push_swap.c \
					./special_case_one.c \
					./special_case_two.c \
					./utils_bits.c \
					./utils_lst.c \
					./utils_check.c \
					./utils_stack.c \
					./utils_more.c \
					./utils_more2.c \
					./moves_one.c \
					./moves_two.c \
					./moves_three.c \
					./spliting.c 

OBJS			= 	$(SRCS:.c=.o)

LIBS			= 	-L ./ft_printf -lftprintf

CC				= 	gcc
RM				= 	rm -f
CFLAGS			= 	-Wall -Wextra -Werror

NAME			= 	push_swap

all:			$(NAME)

$(NAME):		$(OBJS)
				@make -C ./ft_printf
				gcc $(CFLAGS) -g3 -o $(NAME) $(OBJS) $(LIBS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(OBJS)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
