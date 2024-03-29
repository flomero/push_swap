/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:53:10 by flfische          #+#    #+#             */
/*   Updated: 2024/03/29 13:17:36 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	*ft_get_input_error(void)
{
	static int	error;

	return (&error);
}

void	ft_set_input_error(int error)
{
	*ft_get_input_error() = error;
}

int	ft_atoi_ps(const char *str)
{
	int	i;
	int	is_negativ;
	int	out;

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
	if (str[i] != '\0')
		ft_set_input_error(1);
	if (is_negativ)
		out = -1 * out;
	return (out);
}

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

int	ft_parse_input(int argc, char **argv, int **array)
{
	int		i;
	int		j;
	int		count;
	int		arr_size;
	char	**split;

	i = 1;
	j = 0;
	arr_size = argc - 1;
	*array = malloc(sizeof(int) * arr_size);
	if (*array == NULL)
		return (-1);
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (split == NULL)
			return (ft_set_input_error(1), 0);
		count = 0;
		while (split[count] != NULL)
		{
			if (j >= arr_size)
				*array = ft_realloc_int(*array, &arr_size);
			(*array)[j] = ft_atoi_ps(split[count]);
			j++;
			if (*ft_get_input_error() == 1)
				return (ft_free_str_array(split), 0);
			free(split[count]);
			count++;
		}
		free(split);
		i++;
	}
	return (j);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*input;

	input = NULL;
	if (argc < 2)
		return (0);
	i = ft_parse_input(argc, argv, &input);
	ft_putintarr_fd(input, i, 1);
	return (0);
}
