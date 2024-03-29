/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:55:16 by flfische          #+#    #+#             */
/*   Updated: 2024/03/29 17:19:14 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_ops	ft_parse_op(char *op)
{
	if (!ft_strcmp(op, "sa") || !ft_strcmp(op, "sa\n"))
		return (sa);
	if (!ft_strcmp(op, "sb") || !ft_strcmp(op, "sb\n"))
		return (sb);
	if (!ft_strcmp(op, "ss") || !ft_strcmp(op, "ss\n"))
		return (ss);
	if (!ft_strcmp(op, "pa") || !ft_strcmp(op, "pa\n"))
		return (pa);
	if (!ft_strcmp(op, "pb") || !ft_strcmp(op, "pb\n"))
		return (pb);
	if (!ft_strcmp(op, "ra") || !ft_strcmp(op, "ra\n"))
		return (ra);
	if (!ft_strcmp(op, "rb") || !ft_strcmp(op, "rb\n"))
		return (rb);
	if (!ft_strcmp(op, "rr") || !ft_strcmp(op, "rr\n"))
		return (rr);
	if (!ft_strcmp(op, "rra") || !ft_strcmp(op, "rra\n"))
		return (rra);
	if (!ft_strcmp(op, "rrb") || !ft_strcmp(op, "rrb\n"))
		return (rrb);
	if (!ft_strcmp(op, "rrr") || !ft_strcmp(op, "rrr\n"))
		return (rrr);
	return (-1);
}

int	ft_execute_ops(t_push_swap *ps, t_ops op)
{
	if (op == sa)
		ft_swap_a(ps);
	else if (op == sb)
		ft_swap_b(ps);
	else if (op == ss)
		ft_swap_both(ps);
	else if (op == pa)
		ft_push_a(ps);
	else if (op == pb)
		ft_push_b(ps);
	else if (op == ra)
		ft_rot_a(ps);
	else if (op == rb)
		ft_rot_b(ps);
	else if (op == rr)
		ft_rot_both(ps);
	else if (op == rra)
		ft_revrot_a(ps);
	else if (op == rrb)
		ft_revrot_b(ps);
	else if (op == rrr)
		ft_revrot_both(ps);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int			*array;
	int			len;
	char		*line;
	t_ops		op;
	t_push_swap	*ps;

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
	ps = malloc(sizeof(t_push_swap));
	if (!ps)
	{
		free(array);
		ft_printf("Error\n");
		return (1);
	}
	ps->input = array;
	ps->size = len;
	ps->print = 0;
	ft_init_stacks(ps);
	line = get_next_line(0);
	while (line)
	{
		op = ft_parse_op(line);
		if (op == -1)
		{
			free(ps->a.stack);
			free(ps->b.stack);
			free(ps->input);
			free(ps);
			ft_printf("Error\n");
			return (1);
		}
		if (!ft_execute_ops(ps, op))
		{
			free(ps->a.stack);
			free(ps->b.stack);
			free(ps->input);
			free(ps);
			ft_printf("Error\n");
			return (1);
		}
		free(line);
		line = get_next_line(0);
	}
	if (ft_is_sorted(ps->a.stack, len))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	// ft_putintarr_fd(ps->a.stack, ps->a.len, 1);
	free(ps->a.stack);
	free(ps->b.stack);
	free(ps->input);
	free(ps);
	return (0);
}
