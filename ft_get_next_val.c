/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_val.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:39:16 by flfische          #+#    #+#             */
/*   Updated: 2024/04/07 11:49:07 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_get_next_index(t_stack *stack, t_range range)
{
	int	i;
	int	closest;

	i = 0;
	while (i < stack->len)
	{
		if (stack->stack[i] >= range.min && stack->stack[i] <= range.max)
		{
			closest = i;
			break ;
		}
		i++;
	}
	while (i < stack->len)
	{
		if (stack->stack[i] >= range.min && stack->stack[i] <= range.max)
			if (stack->len - i < closest)
				closest = i;
		i++;
	}
	return (closest);
}
