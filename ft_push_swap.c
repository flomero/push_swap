/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:53:10 by flfische          #+#    #+#             */
/*   Updated: 2024/04/09 10:25:57 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_print_ps(t_push_swap *ps)
{
	ft_printf("input: \n");
	ft_putintarr_fd(ps->input.stack, ps->input.len, 1);
	ft_printf("a: \n");
	ft_putintarr_fd(ps->a.stack, ps->a.len, 1);
	ft_printf("b: \n");
	ft_putintarr_fd(ps->b.stack, ps->b.len, 1);
}

int	main(int argc, char **argv)
{
	int			len;
	t_stack		input;
	t_push_swap	*ps;

	if (argc < 2)
		return (0);
	ft_set_input_error(0);
	len = ft_parse_input(argc, argv, &input.stack);
	if (len == 0)
		return (ft_printf("Error\n"), 1);
	if (*ft_get_input_error() == 1)
		return (free(input.stack), ft_printf("Error\n"), 1);
	if (ft_is_sorted(input.stack, len))
		return (free(input.stack), 0);
	ps = malloc(sizeof(t_push_swap));
	if (!ps)
		return (free(input.stack), ft_printf("Error\n"), 1);
	ft_init_stacks(ps, input.stack, len, 0);
	ft_bubble_sort(ps->a.stack, ps->a.len);
	ft_get_indices(&ps->input, &ps->a);
	ft_memcpy(ps->a.stack, ps->input.stack, sizeof(int) * ps->input.len);
	ps->print = 1;
	if (ps->a.len == 2)
		ft_swap_a(ps);
	else if (ps->a.len == 3)
		ft_sort_three(ps);
	else if (ps->a.len <= 5)
		ft_sort_five(ps);
	else
		ft_sort(ps);
	ft_print_last_op(0);
	ft_free_stacks(ps);
	return (0);
}
