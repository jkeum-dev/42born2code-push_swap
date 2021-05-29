NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -g3 -fsanitize=address

AR = ar
ARFLAGS = rc

SRCS_DIR =	./srcs				\
			./srcs/operations

OBJS_DIR = ./objs
INC_DIR = ./includes

LIBFT = libft.a
LIBFT_DIR = ./libft

SRCS =	./srcs/main.c			\
		./srcs/check_arg.c		\
		./srcs/ft_atoi.c		\
		./srcs/get_max_min_value.c	\
		./srcs/handle_under_three.c	\
		./srcs/init_stack.c		\
		./srcs/push_swap.c		\
		./srcs/sort_a_to_b.c		\
		./srcs/sort_arg_three.c		\
		./srcs/sort_b_to_a.c		\
		./srcs/operations/push.c			\
		./srcs/operations/reverse_rotate.c	\
		./srcs/operations/rotate.c			\
		./srcs/operations/swap.c

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(SRCS_DIR)

RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I$(INC_DIR) -I$(LIBFT_DIR) -c $^

clean :
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all