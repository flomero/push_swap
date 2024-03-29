/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:29:00 by flfische          #+#    #+#             */
/*   Updated: 2024/03/29 13:28:05 by flfische         ###   ########.fr       */
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

#endif
