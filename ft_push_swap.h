/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:29:00 by flfische          #+#    #+#             */
/*   Updated: 2024/03/29 15:04:27 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	*stack;
	int	len;
}		t_stack;

typedef struct s_push_swap
{
	int		*input;
	int		size;
	t_stack	a;
	t_stack	b;
}		t_push_swap;

// generic stack operations
void	ft_do_swap(t_stack *stack);
void	ft_do_rot(t_stack *stack);
void	ft_do_revrot(t_stack *stack);
void	ft_push_stacks(t_stack *from, t_stack *to);

// input
int		ft_parse_input(int argc, char **argv, int **array);
int		ft_atoi_ps(const char *str);
int		*ft_get_input_error(void);
void	ft_set_input_error(int error);

// array utils
int		*ft_realloc_int(int *array, int *size);
void	ft_free_str_array(char **array);

// checks
int		ft_is_sorted(int *stack, int len);

#endif
