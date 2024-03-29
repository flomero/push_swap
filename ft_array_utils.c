/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:34:13 by flfische          #+#    #+#             */
/*   Updated: 2024/03/29 14:34:55 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_free_str_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
}

int	*ft_realloc_int(int *array, int *size)
{
	int	*new_array;
	int	i;

	new_array = malloc(sizeof(int) * (*size * 2));
	if (new_array == NULL)
		return (NULL);
	i = 0;
	while (i < *size)
	{
		new_array[i] = array[i];
		i++;
	}
	*size *= 2;
	free(array);
	return (new_array);
}