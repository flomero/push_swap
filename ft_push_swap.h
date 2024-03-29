/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:29:00 by flfische          #+#    #+#             */
/*   Updated: 2024/03/29 14:36:46 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_push_swap
{
	int	*stack_a;
	int	*stack_b;
	int	*input;
	int	stack_size;
	int	pos_a;
	int	pos_b;
}		t_push_swap;

// single stack operations
void	ft_do_swap(int *stack, int len);
void	ft_do_rot(int *stack, int len);
void	ft_do_revrot(int *stack, int len);

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
