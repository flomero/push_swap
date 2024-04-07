/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:37:42 by flfische          #+#    #+#             */
/*   Updated: 2024/04/07 17:21:36 by flfische         ###   ########.fr       */
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

void	ft_sort_back(t_push_swap *ps)
{
	while (ps->b.len > 0)
	{
		ft_highest_to_top_b(ps);
		ft_push_a(ps);
	}
}

void	ft_sort_hundred(t_push_swap *ps)
{
	int	i;
	int	j;
	int	cmin;
	int	cmax;

	i = 0;
	while (i < CHUCKS_100)
	{
		cmin = i * ps->input.len / CHUCKS_100;
		cmax = (i + 1) * ps->input.len / CHUCKS_100;
		j = 0;
		while (j < 20)
		{
			ft_get_next_val(ps, (t_range){cmin, cmax});
			ft_push_b(ps);
			j++;
		}
		i++;
	}
	ft_sort_back(ps);
}
