CC = cc
#CFLAGS = -Wall -Wextra -Werror

CFILES := \
	ft_generic_stack_ops.c \
	ft_doop_a.c \
	ft_doop_b.c \
	ft_doop_both.c \
	ft_checks.c \
	ft_input.c \
	ft_init.c \
	ft_input_errors.c \
	ft_array_utils.c \
	ft_simple_sort.c \
	ft_sort_three.c \
	ft_sort_five.c \

BONUSFILES := $(CFILES)
BONUSFILES += ft_checker.c

CFILES += ft_push_swap.c

OBJDIR := obj
OFILES := $(addprefix $(OBJDIR)/, $(CFILES:.c=.o))
BONUS_OFILES := $(addprefix $(OBJDIR)/, $(BONUSFILES:.c=.o))

NAME := push_swap
BONUS_NAME := checker

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
HEADER := ft_push_swap.h

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(LIBFT) $(OBJDIR) $(OFILES)
	$(CC) $(CFLAGS) -o $@ $(OFILES) -L$(LIBFT_DIR) -lft

$(BONUS_NAME): $(LIBFT) $(OBJDIR) $(BONUS_OFILES)
	$(CC) $(CFLAGS) -o $@ $(BONUS_OFILES) -L$(LIBFT_DIR) -lft

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJDIR)/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
