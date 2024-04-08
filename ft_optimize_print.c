/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:43:10 by flfische          #+#    #+#             */
/*   Updated: 2024/04/08 13:56:51 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_print_ops(t_ops op)
{
	if (op == sa)
		ft_printf("sa\n");
	else if (op == sb)
		ft_printf("sb\n");
	else if (op == ss)
		ft_printf("ss\n");
	else if (op == pa)
		ft_printf("pa\n");
	else if (op == pb)
		ft_printf("pb\n");
	else if (op == ra)
		ft_printf("ra\n");
	else if (op == rb)
		ft_printf("rb\n");
	else if (op == rr)
		ft_printf("rr\n");
	else if (op == rra)
		ft_printf("rra\n");
	else if (op == rrb)
		ft_printf("rrb\n");
	else if (op == rrr)
		ft_printf("rrr\n");
}

void	ft_print_last_op(t_ops op)
{
	static t_ops	last_op;

	if (op == last_op)
		ft_print_ops(op);
	else if (!last_op)
		last_op = op;
	else if ((op == ra && last_op == rra) || (op == rra && last_op == ra)
		|| (op == rb && last_op == rrb) || (op == rrb && last_op == rb)
		|| (op == pa && last_op == pb) || (op == pb && last_op == pa))
		last_op = not ;
	else if ((op == ra && last_op == rb) || (op == rb && last_op == ra))
	{
		ft_print_ops(rr);
		last_op = not ;
	}
	else if ((op == rra && last_op == rrb) || (op == rrb && last_op == rra))
	{
		ft_print_ops(rrr);
		last_op = not ;
	}
	else
	{
		ft_print_ops(last_op);
		last_op = op;
	}
}
