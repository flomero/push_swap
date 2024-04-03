/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:53:10 by flfische          #+#    #+#             */
/*   Updated: 2024/04/03 14:31:55 by flfische         ###   ########.fr       */
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
	ft_bubble_sort(input->stack, input->len);
	ft_printf("is_sorted: %d\n", ft_is_sorted(input->stack, input->len));
	free(input->stack);
	free(input);
	return (0);
}
