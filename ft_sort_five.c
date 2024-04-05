/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:48:01 by flfische          #+#    #+#             */
/*   Updated: 2024/04/05 19:33:09 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_five(t_push_swap *ps)
{
	ft_push_b(ps);
	ft_push_b(ps);
	ft_sort_three(ps);
	if (ps->b.stack[0] > ps->b.stack[1])
		ft_swap_b(ps);
	while (ps->b.len > 0)
	{
		while (1)
		{
			if (ps->b.stack[0] < ps->a.stack[0]
				|| (ps->b.stack[0] > ps->a.stack[ps->a.len - 1]
					&& ps->b.stack[0] > ps->a.stack[0]))
			{
				ft_push_a(ps);
				break ;
			}
			ft_rot_a(ps);
		}
	}
	if (ps->a.stack[1] == 0 || ps->a.stack[2] == 0)
		while (ps->a.stack[0] != 0)
			ft_rot_a(ps);
	else
		while (ps->a.stack[0] != 0)
			ft_revrot_a(ps);
}
