SRCS = main.c \
	   t_ps.c \
	   t_psa.c \
	   t_stack.c \
	   t_stack2.c \
	   t_stack_info.c \
	   algonaif.c \
	   algobubble.c \
	   algom.c \
	   checkinput.c \
	   param.c \
	   t_dnode.c \
	   move.c \
	   move2.c \
	   move3.c

NAME = push_swap
GCC_FLAGS = #-Wall -Werror -Wextra
CC = gcc $(GCC_FLAGS)
SRCDIR = ./
OBJDIR = ./objs
AR = ar -cq
RM = rm -rf
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIBFT = ./libft/libft.a

all: $(NAME)

$(LIBFT):
	@make -C libft
	@echo $(SRC_LIB_O)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) -lft -L./libft/

$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $^

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)
	@make -C libft fclean

re: fclean all

test: fclean all
	rm -f test
	gcc libftprintf.a main.c -o test
	./test
