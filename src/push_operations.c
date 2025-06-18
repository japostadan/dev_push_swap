/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japostad <japostad@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:14:03 by japostad          #+#    #+#             */
/*   Updated: 2025/06/18 11:18:11 by japostad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	push(t_node **in, t_node **out);

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
