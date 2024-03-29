/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:06:14 by flfische          #+#    #+#             */
/*   Updated: 2024/03/29 15:09:41 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap_a(t_push_swap *ps)
{
	ft_do_swap(&ps->a);
	if (ps->print)
		ft_putendl_fd("sa", 1);
}

void	ft_rot_a(t_push_swap *ps)
{
	ft_do_rot(&ps->a);
	if (ps->print)
		ft_putendl_fd("ra", 1);
}

void	ft_revrot_a(t_push_swap *ps)
{
	ft_do_revrot(&ps->a);
	if (ps->print)
		ft_putendl_fd("rra", 1);
}

void	ft_push_a(t_push_swap *ps)
{
	ft_push_stacks(&ps->b, &ps->a);
	if (ps->print)
		ft_putendl_fd("pa", 1);
}
