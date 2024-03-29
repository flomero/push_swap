CC = cc
#CFLAGS = -Wall -Wextra -Werror

CFILES := \
	single_stack_ops.c \
	checks.c \

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
