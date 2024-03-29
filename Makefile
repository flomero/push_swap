CC = cc
#CFLAGS = -Wall -Wextra -Werror

CFILES := \
	ft_push_swap.c \
	single_stack_ops.c \

OBJDIR := obj
OFILES := $(addprefix $(OBJDIR)/, $(CFILES:.c=.o))

NAME := push_swap

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
HEADER := ft_push_swap.h

all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(OBJDIR) $(OFILES)
	$(CC) $(CFLAGS) -o $@ $(OFILES) -L$(LIBFT_DIR) -lft

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
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
