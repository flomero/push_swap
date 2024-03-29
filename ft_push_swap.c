/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:53:10 by flfische          #+#    #+#             */
/*   Updated: 2024/03/29 15:21:40 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*input;

	input = malloc(sizeof(t_stack));
	if (!input)
		return (1);
	input->stack = NULL;
	if (argc < 2)
		return (0);
	input->len = ft_parse_input(argc, argv, &input->stack);
	ft_putintarr_fd(input->stack, input->len, 1);
	ft_printf("--------------------------------\n");
	ft_printf("is_sorted: %d\n", ft_is_sorted(input->stack, input->len));
	ft_printf("--------------------------------\n");
	ft_do_revrot(input);
	ft_putintarr_fd(input->stack, input->len, 1);
	ft_printf("--------------------------------\n");
	ft_printf("is_sorted: %d\n", ft_is_sorted(input->stack, input->len));
	return (0);
}
