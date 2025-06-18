/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japostad <japostad@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:15:49 by japostad          #+#    #+#             */
/*   Updated: 2025/06/18 11:28:59 by japostad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_2(t_stack *stack)
{
	if (stack->a->val > stack->a->next->val)
		sa(&stack, 1);
}

void	sort_3(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->a->val;
	b = stack->a->next->val;
	c = stack->a->next->next->val;
	if (a > b && b < c && a < c)
		sa(&stack, 1);
	else if (a > b && b > c && a > c)
	{
		sa(&stack, 1);
		rra(&stack, 1);
	}
	else if (a > b && b < c && a > c)
		ra(&stack, 1);
	else if (a < b && b > c && a < c)
	{
		sa(&stack, 1);
		ra(&stack, 1);
	}
	else if (a < b && b > c && a > c)
		rra(&stack, 1);
}

void	sort_4(t_stack *stack)
{
	int	min_pos;

	min_pos = find_min_position(stack->a);
	if (min_pos == 1)
		ra(&stack, 1);
	else if (min_pos == 2)
		repeat_until(ra, &stack, 2);
	else if (min_pos == 3)
		rra(&stack, 1);
	pb(&stack, 1);
	sort_3(stack);
	pa(&stack, 1);
}

void	sort_5(t_stack **stack)
{
	int	min_pos;

	min_pos = find_min_position((*stack)->a);
	if (min_pos == 1)
		ra(stack, 1);
	else if (min_pos == 2)
		repeat_until(ra, stack, 2);
	else if (min_pos == 3)
		repeat_until(rra, stack, 2);
	else if (min_pos == 4)
		rra(stack, 1);
	pb(stack, 1);
	min_pos = find_min_position((*stack)->a);
	if (min_pos == 1)
		ra(stack, 1);
	else if (min_pos == 2)
		repeat_until(ra, stack, 2);
	else if (min_pos == 3)
		rra(stack, 1);
	pb(stack, 1);
	sort_3(*stack);
	repeat_until(pa, stack, 2);
}
