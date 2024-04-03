/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:25:08 by flfische          #+#    #+#             */
/*   Updated: 2024/04/03 14:53:02 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_bubble_sort(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;
	int	swapped;

	i = 0;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				swapped = 1;
			}
			j++;
		}
		i++;
	}
}

void	ft_get_indices(t_stack *src, t_stack *dst)
{
	int	i;
	int	j;

	i = 0;
	while (i < src->len)
	{
		j = 0;
		while (j < dst->len)
		{
			if (src->stack[i] == dst->stack[j])
			{
				src->stack[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}
