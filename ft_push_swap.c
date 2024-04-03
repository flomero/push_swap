/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:53:10 by flfische          #+#    #+#             */
/*   Updated: 2024/04/03 15:58:33 by flfische         ###   ########.fr       */
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
	// ft_printf("len: %d\n", len);
	if (len == 0)
		return (ft_printf("Error\n"), 1);
	if (*ft_get_input_error() == 1)
		return (free(input.stack), ft_printf("Error\n"), 1);
	ps = malloc(sizeof(t_push_swap));
	if (!ps)
		return (free(input.stack), ft_printf("Error\n"), 1);
	ft_init_stacks(ps, input.stack, len, 0);
	ft_bubble_sort(ps->a.stack, ps->a.len);
	ft_print_ps(ps);
	ft_get_indices(&ps->a, &ps->input);
	ft_print_ps(ps);
	ft_free_stacks(ps);
	return (0);
}
