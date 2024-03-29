/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:08:43 by flfische          #+#    #+#             */
/*   Updated: 2024/03/29 15:14:10 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap_b(t_push_swap *ps)
{
	ft_do_swap(&ps->b);
	if (ps->print)
		ft_putendl_fd("sb", 1);
}

void	ft_rot_b(t_push_swap *ps)
{
	ft_do_rot(&ps->b);
	if (ps->print)
		ft_putendl_fd("rb", 1);
}

void	ft_revrot_b(t_push_swap *ps)
{
	ft_do_revrot(&ps->b);
	if (ps->print)
		ft_putendl_fd("rrb", 1);
}

void	ft_push_b(t_push_swap *ps)
{
	ft_push_stacks(&ps->a, &ps->b);
	if (ps->print)
		ft_putendl_fd("pb", 1);
}
