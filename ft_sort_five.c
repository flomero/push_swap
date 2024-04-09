/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:48:01 by flfische          #+#    #+#             */
/*   Updated: 2024/04/09 12:17:50 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_fits_here(t_stack stack, int i)
{
	if (stack.len < 2)
		return (1);
	if (i < stack.stack[0] && i > stack.stack[stack.len - 1])
		return (1);
	if (stack.stack[0] == 0 && i > stack.stack[stack.len - 1])
		return (1);
	if (i > stack.stack[0] && i > stack.stack[stack.len - 1]
		&& stack.stack[0] < stack.stack[stack.len - 1])
		return (1);
	if (i < stack.stack[0] && i < stack.stack[stack.len - 1])
		return (1);
	return (0);
}

void	ft_sort_five(t_push_swap *ps)
{
	while (ps->a.len > 3)
	{
		if (ps->a.stack[0] == 0 || (ps->a.stack[0] == 1 && ps->input.len == 5))
			ft_push_b(ps);
		else
			ft_rot_a(ps);
	}
	ft_sort_three(ps);
	if (ps->b.stack[0] < ps->b.stack[1] && ps->input.len == 5)
		ft_swap_b(ps);
	ft_push_a(ps);
	ft_push_a(ps);
}
