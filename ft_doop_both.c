/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:11:29 by flfische          #+#    #+#             */
/*   Updated: 2024/03/29 15:12:44 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap_both(t_push_swap *ps)
{
	ft_do_swap(&ps->a);
	ft_do_swap(&ps->b);
	if (ps->print)
		ft_putendl_fd("ss", 1);
}

void	ft_rot_both(t_push_swap *ps)
{
	ft_do_rot(&ps->a);
	ft_do_rot(&ps->b);
	if (ps->print)
		ft_putendl_fd("rr", 1);
}

void	ft_revrot_both(t_push_swap *ps)
{
	ft_do_revrot(&ps->a);
	ft_do_revrot(&ps->b);
	if (ps->print)
		ft_putendl_fd("rrr", 1);
}
