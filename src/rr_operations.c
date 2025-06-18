/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japostad <japostad@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:15:18 by japostad          #+#    #+#             */
/*   Updated: 2025/06/18 11:22:53 by japostad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra(t_stack **stack, int print)
{
	t_node	*tail;
	t_node	*tail_prev;
	t_node	*head;

	if (!(*stack)->a || !(*stack)->a->next)
		return ;
	tail_prev = (*stack)->a;
	head = (*stack)->a;
	while (tail_prev->next->next)
		tail_prev = tail_prev->next;
	tail = tail_prev->next;
	tail_prev->next = NULL;
	tail->next = head;
	(*stack)->a = tail;
	if (print)
		print_operation("rra\n");
}

void	rrb(t_stack **stack, int print)
{
	t_node	*tail;
	t_node	*tail_prev;
	t_node	*head;

	if (!(*stack)->b || !(*stack)->b->next)
		return ;
	tail_prev = (*stack)->b;
	head = (*stack)->b;
	while (tail_prev->next->next)
		tail_prev = tail_prev->next;
	tail = tail_prev->next;
	tail_prev->next = NULL;
	tail->next = head;
	(*stack)->b = tail;
	if (print)
		print_operation("rrb\n");
}

void	rrr(t_stack **stack, int print)
{
	rra(stack, 0);
	rrb(stack, 0);
	if (print)
		print_operation("rrr\n");
}
