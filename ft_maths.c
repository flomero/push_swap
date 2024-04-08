/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:23:40 by flfische          #+#    #+#             */
/*   Updated: 2024/04/08 11:49:12 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_lower_sqrt_search(int nb, int low, int high);

int	ft_lower_sqrt(int nb)
{
	if (nb <= 0)
		return (0);
	return (ft_lower_sqrt_search(nb, 0, nb));
}

int	ft_lower_sqrt_search(int b, int low, int high)
{
	int	mid;

	if (low >= high - 1)
		return (low);
	if (low <= high)
	{
		mid = low + (high - low) / 2;
		if (mid > 46340)
			return (ft_lower_sqrt_search(b, low, 46340));
		if (mid * mid == b)
			return (mid);
		if (mid * mid < b)
			return (ft_lower_sqrt_search(b, mid + 1, high));
		else
			return (ft_lower_sqrt_search(b, low, mid - 1));
	}
	return (0);
}
