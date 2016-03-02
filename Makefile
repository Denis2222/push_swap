SRCS = main.c \
	   t_ps.c \
	   t_stack.c \
	   algonaif.c \
	   checkinput.c \
	   t_dnode.c

NAME = push_swap
GCC_FLAGS = -Wall -Werror -Wextra -g
CC = gcc $(GCC_FLAGS)
SRCDIR = ./
OBJDIR = ./objs
AR = ar -cq
RM = rm -rf
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIBFT = ./libftprintf/libftprintf.a

all: $(NAME)

$(LIBFT):
	@make -C libftprintf
	@echo $(SRC_LIB_O)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) -lftprintf -L./libftprintf/ 

$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $^

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)
	@make -C libftprintf fclean

re: fclean all

test: fclean all
	rm -f test
	gcc libftprintf.a main.c -o test
	./test

