/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:18:50 by flfische          #+#    #+#             */
/*   Updated: 2024/03/29 13:22:49 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_do_swap(int *stack, int len)
{
	int	tmp;

	if (len < 2)
		return ;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	ft_do_rot(int *stack, int len)
{
	int	tmp;
	int	i;

	if (len < 2)
		return ;
	tmp = stack[0];
	i = 0;
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = tmp;
}

void	ft_do_revrot(int *stack, int len)
{
	int	tmp;
	int	i;

	if (len < 2)
		return ;
	tmp = stack[len - 1];
	i = len - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = tmp;
}
