/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:55:16 by flfische          #+#    #+#             */
/*   Updated: 2024/03/29 14:46:58 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	int	*array;
	int	len;

	if (argc < 2)
		return (0);
	ft_set_input_error(0);
	len = ft_parse_input(argc, argv, &array);
	if (*ft_get_input_error() == 1)
	{
		free(array);
		ft_printf("Error\n");
		return (1);
	}

	if (ft_is_sorted(array, len))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(array);
	return (0);
}
