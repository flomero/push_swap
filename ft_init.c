/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:52:05 by flfische          #+#    #+#             */
/*   Updated: 2024/04/09 13:56:39 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_init_stacks(t_push_swap *ps, int *arr, int size, int print)
{
	ps->input.stack = arr;
	ps->input.len = size;
	ps->print = print;
	ps->a.stack = malloc(sizeof(int) * ps->input.len);
	if (!ps->a.stack)
	{
		free(ps->input.stack);
		free(ps);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	ps->b.stack = malloc(sizeof(int) * ps->input.len);
	if (!ps->b.stack)
	{
		free(ps->a.stack);
		free(ps->input.stack);
		free(ps);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	ps->a.len = ps->input.len;
	ps->b.len = 0;
	ft_memcpy(ps->a.stack, ps->input.stack, sizeof(int) * ps->input.len);
}

void	ft_free_stacks(t_push_swap *ps)
{
	free(ps->a.stack);
	free(ps->b.stack);
	free(ps->input.stack);
	free(ps);
}
