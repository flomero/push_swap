/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:36:13 by flfische          #+#    #+#             */
/*   Updated: 2024/04/05 17:40:52 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_three(t_push_swap *ps)
{
	int	*arr;

	arr = ps->a.stack;
	if (arr[0] < arr[1] && arr[2] > arr[0])
	{
		ft_swap_a(ps);
		ft_rot_a(ps);
	}
	else if (arr[0] > arr[1] && arr[2] > arr[0])
		ft_swap_a(ps);
	else if (arr[0] < arr[1] && arr[2] < arr[0])
		ft_revrot_a(ps);
	else if (arr[0] > arr[1] && arr[2] > arr[1])
		ft_rot_a(ps);
	else if (arr[0] > arr[1] && arr[2] < arr[1])
	{
		ft_swap_a(ps);
		ft_revrot_a(ps);
	}
}
