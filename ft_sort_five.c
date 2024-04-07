/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:48:01 by flfische          #+#    #+#             */
/*   Updated: 2024/04/07 11:26:33 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_five(t_push_swap *ps)
{
	ft_push_b(ps);
	if (ps->input.len == 5)
		ft_push_b(ps);
	ft_sort_three(ps);
	if (ps->b.stack[0] > ps->b.stack[1] && ps->input.len == 5)
		ft_swap_b(ps);
	while (ps->b.len > 0)
	{
		if (ps->b.stack[0] < ps->a.stack[0]
			|| (ps->b.stack[0] > ps->a.stack[ps->a.len - 1]
				&& ps->b.stack[0] > ps->a.stack[0]))
			ft_push_a(ps);
		else if (ps->b.stack[0] > ps->a.stack[0])
			ft_rot_a(ps);
	}
	if (ps->a.stack[1] == 0 || ps->a.stack[2] == 0)
		while (ps->a.stack[0] != 0)
			ft_rot_a(ps);
	else
		while (ps->a.stack[0] != 0)
			ft_revrot_a(ps);
}
