/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:53:10 by flfische          #+#    #+#             */
/*   Updated: 2024/03/29 14:24:52 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	*input;

	input = NULL;
	if (argc < 2)
		return (0);
	i = ft_parse_input(argc, argv, &input);
	ft_putintarr_fd(input, i, 1);
	ft_printf("--------------------------------\n");
	ft_printf("is_sorted: %d\n", ft_is_sorted(input, i));
	ft_printf("--------------------------------\n");
	ft_do_revrot(input, i);	
	ft_putintarr_fd(input, i, 1);
	ft_printf("--------------------------------\n");
	ft_printf("is_sorted: %d\n", ft_is_sorted(input, i));
	return (0);
}
