NAME = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -g3 -fsanitize=address

# ifeq ($(DEBUG),true)
# 	CFLAGS += -g
# endif

AR = ar
ARFLAGS = rc

SRCS_DIR =	./srcs				\
			./srcs/gnl			\
			./srcs/operations	\
			./srcs/pre_settings

OBJS_DIR = ./objs
INC_DIR = ./includes

LIBFT = libft.a
LIBFT_DIR = ../libft

SRCS =	./srcs/gnl/get_next_line_bonus.c		\
		./srcs/gnl/get_next_line_utils_bonus.c	\
		./srcs/operations/push.c			\
		./srcs/operations/reverse_rotate.c	\
		./srcs/operations/swap.c			\
		./srcs/operations/rotate.c			\
		./srcs/pre_settings/check_arg.c		\
		./srcs/pre_settings/ft_atoi.c		\
		./srcs/pre_settings/init_stack.c	\
		./srcs/main.c			\
		./srcs/checker.c		\
		./srcs/do_operations.c	\
		./srcs/free.c

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(SRCS_DIR)

RM = rm -f

all : $(NAME)

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