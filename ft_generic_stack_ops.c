/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_single_stack_ops.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:18:50 by flfische          #+#    #+#             */
/*   Updated: 2024/03/29 15:03:26 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_do_swap(t_stack *stack)
{
	int	tmp;

	if (stack->len < 2)
		return ;
	tmp = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = tmp;
}

void	ft_do_rot(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->len < 2)
		return ;
	tmp = stack->stack[0];
	i = 0;
	while (i < stack->len - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[i] = tmp;
}

void	ft_do_revrot(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->len < 2)
		return ;
	tmp = stack->stack[stack->len - 1];
	i = stack->len - 1;
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[i] = tmp;
}

void	ft_push_stacks(t_stack *from, t_stack *to)
{
	int	tmp;

	if (from->len < 1)
		return ;
	tmp = from->stack[0];
	ft_stack_pop(from);
	ft_stack_push(to, tmp);
}
