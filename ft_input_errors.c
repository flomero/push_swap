/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:08:21 by flfische          #+#    #+#             */
/*   Updated: 2024/03/29 14:10:24 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_get_input_error(void)
{
	static int	error;

	return (&error);
}

void	ft_set_input_error(int error)
{
	*ft_get_input_error() = error;
}
