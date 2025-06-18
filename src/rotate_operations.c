/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japostad <japostad@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:14:59 by japostad          #+#    #+#             */
/*   Updated: 2025/06/18 11:20:05 by japostad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_stack **stack, int print)
{
	t_node	*head;
	t_node	*temp;

	if (!(*stack)->a || !(*stack)->a->next)
		return ;
	head = (*stack)->a;
	temp = (*stack)->a;
	while (temp->next)
		temp = temp->next;
	temp->next = head;
	(*stack)->a = head->next;
	head->next = NULL;
	if (print)
		print_operation("ra\n");
}

void	rb(t_stack **stack, int print)
{
	t_node	*head;
	t_node	*temp;

	if (!(*stack)->b || !(*stack)->b->next)
		return ;
	head = (*stack)->b;
	temp = (*stack)->b;
	while (temp->next)
		temp = temp->next;
	temp->next = head;
	(*stack)->b = head->next;
	head->next = NULL;
	if (print)
		print_operation("rb\n");
}

void	rr(t_stack **stack, int print)
{
	ra(stack, 0);
	rb(stack, 0);
	if (print)
		print_operation("rr\n");
}
