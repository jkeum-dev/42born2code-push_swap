NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -g3 -fsanitize=address

# ifeq ($(DEBUG),true)
# 	CFLAGS += -g
# endif

AR = ar
ARFLAGS = rc

SRCS_DIR =	./srcs				\
			./srcs/operations	\
			./srcs/pre_settings	\
			./srcs/sort

OBJS_DIR = ./objs
INC_DIR = ./includes

LIBFT = libft.a
LIBFT_DIR = ./libft

SRCS =	./srcs/main.c			\
		./srcs/operations/push.c			\
		./srcs/operations/reverse_rotate.c	\
		./srcs/operations/swap.c			\
		./srcs/operations/rotate.c			\
		./srcs/pre_settings/check_arg.c	\
		./srcs/pre_settings/ft_atoi.c	\
		./srcs/pre_settings/init_stack.c\
		./srcs/sort/handle_under_three.c	\
		./srcs/sort/sort_a_to_b.c			\
		./srcs/sort/sort_arg_five.c			\
		./srcs/sort/sort_arg_three_a.c		\
		./srcs/sort/sort_arg_three_b.c		\
		./srcs/sort/sort_b_to_a.c			\
		./srcs/free.c				\
		./srcs/get_max_min_value.c	\
		./srcs/push_swap.c

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(SRCS_DIR)

RM = rm -f

all : $(NAME)

bonus : re
	@$(MAKE) fclean -C ./bonus_checker
	@$(MAKE) -C ./bonus_checker
	@cp ./bonus_checker/checker ./checker

$(NAME) : $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I$(INC_DIR) -I$(LIBFT_DIR) -c $^

clean :
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C bonus_checker fclean
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)
	@if [ -f ./checker ]; then $(RM) ./checker; fi;

re : fclean all