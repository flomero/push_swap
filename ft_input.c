/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:07:45 by flfische          #+#    #+#             */
/*   Updated: 2024/04/10 13:26:45 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_atoi_ps(const char *str)
{
	int			i;
	int			is_negativ;
	long long	out;

	i = 0;
	out = 0;
	is_negativ = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_negativ = 1 - is_negativ;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		out = out * 10 + (str[i] - '0');
		i++;
	}
	if ((i && (str[i - 1] == '-' || str[i - 1] == '+')) || str[i] != '\0')
		ft_set_input_error(1);
	if (is_negativ)
		out = -1 * out;
	if (out > INT_MAX || out < INT_MIN)
		ft_set_input_error(1);
	return (out);
}

int	ft_check_double(int *array, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_parse_split(char **split, int **array, int *j, int *arr_size)
{
	int	count;

	count = 0;
	if (split[0] == NULL)
		return (ft_free_str_array(split, 0), ft_set_input_error(1), 0);
	while (split[count] != NULL)
	{
		if (*j >= *arr_size)
			*array = ft_realloc_int(*array, arr_size);
		(*array)[*j] = ft_atoi_ps(split[count]);
		if (*ft_get_input_error() == 1)
			return (ft_free_str_array(split, count), 0);
		(*j)++;
		free(split[count]);
		count++;
	}
	free(split);
	return (1);
}

int	ft_parse_input(int argc, char **argv, int **array)
{
	int		i;
	int		j;
	int		arr_size;
	char	**split;

	i = 1;
	j = 0;
	arr_size = argc - 1;
	*array = malloc(sizeof(int) * arr_size);
	if (*array == NULL)
		return (ft_set_input_error(1), 0);
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
			return (ft_set_input_error(1), -1);
		split = ft_split(argv[i], ' ');
		if (split == NULL)
			return (ft_set_input_error(1), -1);
		if (!ft_parse_split(split, array, &j, &arr_size))
			return (-1);
		i++;
	}
	if (ft_check_double(*array, j))
		return (ft_set_input_error(1), -1);
	return (j);
}
