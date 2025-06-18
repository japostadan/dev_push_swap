/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japostad <japostad@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:26:54 by japostad          #+#    #+#             */
/*   Updated: 2025/06/12 11:27:01 by japostad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	push(t_node **in, t_node **out)
{
	t_node	*in_head;
	t_node	*out_head;

	if (!in || !*in)
		return (0);
	in_head = *in;
	*in = in_head->next;
	out_head = *out;
	in_head->next = out_head;
	*out = in_head;
	return (1);
}

void	pa(t_stack **stack, int print)
{
	if (!push(&(*stack)->b, &(*stack)->a))
		return ;
	if (print)
		print_operation("pa\n");
}

void	pb(t_stack **stack, int print)
{
	if (!push(&(*stack)->a, &(*stack)->b))
		return ;
	if (print)
		print_operation("pb\n");
}
