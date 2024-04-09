/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:29:00 by flfische          #+#    #+#             */
/*   Updated: 2024/04/09 17:54:18 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"

# define CHUNKS_100 5
# define CHUNKS 10

typedef struct s_stack
{
	int		*stack;
	int		len;
}			t_stack;

typedef struct s_push_swap
{
	int		print;
	t_stack	input;
	t_stack	a;
	t_stack	b;
}			t_push_swap;

typedef struct s_range
{
	int		min;
	int		max;
}			t_range;

typedef enum e_ops
{
	not,
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}			t_ops;

// generic stack operations
void		ft_do_swap(t_stack *stack);
void		ft_do_rot(t_stack *stack);
void		ft_do_revrot(t_stack *stack);
void		ft_push_stacks(t_stack *from, t_stack *to);
// doop a
void		ft_swap_a(t_push_swap *ps);
void		ft_rot_a(t_push_swap *ps);
void		ft_revrot_a(t_push_swap *ps);
void		ft_push_a(t_push_swap *ps);
// doop b
void		ft_swap_b(t_push_swap *ps);
void		ft_rot_b(t_push_swap *ps);
void		ft_revrot_b(t_push_swap *ps);
void		ft_push_b(t_push_swap *ps);
// doop both
void		ft_swap_both(t_push_swap *ps);
void		ft_rot_both(t_push_swap *ps);
void		ft_revrot_both(t_push_swap *ps);
// input checking and parsing
int			ft_parse_input(int argc, char **argv, int **array);
int			ft_atoi_ps(const char *str);
int			ft_check_double(int *array, int len);
int			*ft_get_input_error(void);
void		ft_set_input_error(int error);
void		ft_init_stacks(t_push_swap *ps, int *arr, int size, int print);
// simple sort
void		ft_bubble_sort(int *arr, int len);
void		ft_get_indices(t_stack *src, t_stack *dst);
// stack sort
void		ft_sort_three(t_push_swap *ps);
void		ft_sort_five(t_push_swap *ps);
void		ft_sort(t_push_swap *ps);
void		ft_print_last_op(t_ops op);
// array utils
int			*ft_realloc_int(int *array, int *size);
void		ft_free_str_array(char **array, int index);
// math
int			ft_lower_sqrt(int nb);
// checks
int			ft_is_sorted(int *stack, int len);
// free stuff
void		ft_free_stacks(t_push_swap *ps);

#endif
