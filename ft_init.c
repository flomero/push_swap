/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:52:05 by flfische          #+#    #+#             */
/*   Updated: 2024/03/29 20:13:57 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_init_stacks(t_push_swap *ps, int *arr, int size, int print)
{
	ps->input = arr;
	ps->size = size;
	ps->print = print;
	ps->a.stack = malloc(sizeof(int) * ps->size);
	if (!ps->a.stack)
	{
		free(ps->input);
		free(ps);
		ft_printf("Error\n");
		exit(1);
	}
	ps->b.stack = malloc(sizeof(int) * ps->size);
	if (!ps->b.stack)
	{
		free(ps->a.stack);
		free(ps->input);
		free(ps);
		ft_printf("Error\n");
		exit(1);
	}
	ps->a.len = ps->size;
	ps->b.len = 0;
	ft_memcpy(ps->a.stack, ps->input, sizeof(int) * ps->size);
}

void	ft_free_stacks(t_push_swap *ps)
{
	free(ps->a.stack);
	free(ps->b.stack);
	free(ps->input);
	free(ps);
}
