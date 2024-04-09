/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:37:42 by flfische          #+#    #+#             */
/*   Updated: 2024/04/09 10:18:17 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_highest_to_top_b(t_push_swap *ps)
{
	int	i;
	int	max;
	int	max_i;

	i = 0;
	max = ps->b.stack[0];
	max_i = 0;
	while (i < ps->b.len)
	{
		if (ps->b.stack[i] > max)
		{
			max = ps->b.stack[i];
			max_i = i;
		}
		i++;
	}
	if (max_i < ps->b.len / 2)
		while (ps->b.stack[0] != max)
			ft_rot_b(ps);
	else
		while (ps->b.stack[0] != max)
			ft_revrot_b(ps);
}

void	ft_move_to_fit_b(t_push_swap *ps, int i)
{
	while (!ft_fits_here(ps->b, i))
	{
		ft_rot_b(ps);
	}
}

void	ft_sort_back(t_push_swap *ps)
{
	while (ps->b.len > 0)
	{
		ft_highest_to_top_b(ps);
		ft_push_a(ps);
	}
}

void	ft_sort(t_push_swap *ps)
{
	int	count;
	int	cmax;
	int	val;

	count = 0;
	cmax = ft_lower_sqrt(ps->input.len) * 1.3;
	while (ps->a.len > 0)
	{
		val = ps->a.stack[0];
		if (val < count)
		{
			ft_push_b(ps);
			ft_rot_b(ps);
			count++;
		}
		else if (val <= cmax + count)
		{
			ft_push_b(ps);
			count++;
		}
		else
			ft_rot_a(ps);
	}
	ft_sort_back(ps);
}
