/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:06:14 by flfische          #+#    #+#             */
/*   Updated: 2024/04/08 13:53:56 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap_a(t_push_swap *ps)
{
	ft_do_swap(&ps->a);
	if (ps->print)
		ft_print_last_op(sa);
}

void	ft_rot_a(t_push_swap *ps)
{
	ft_do_rot(&ps->a);
	if (ps->print)
		ft_print_last_op(ra);
}

void	ft_revrot_a(t_push_swap *ps)
{
	ft_do_revrot(&ps->a);
	if (ps->print)
		ft_print_last_op(rra);
}

void	ft_push_a(t_push_swap *ps)
{
	if (ps->b.len > 0)
	{
		ft_push_stacks(&ps->b, &ps->a);
		if (ps->print)
			ft_print_last_op(pa);
	}
}
