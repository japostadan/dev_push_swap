/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japostad <japostad@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:16:16 by japostad          #+#    #+#             */
/*   Updated: 2025/06/18 11:31:24 by japostad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pushswap.h"

static int	pos_in_list(int index, t_node *list);
static int	max_index(t_node *list);

void	sort_max(t_stack *stack, int n)
{
	int	index;
	int	pos;

	while (stack->b)
	{
		index = max_index(stack->b);
		pos = pos_in_list(index, stack->b);
		if (pos < n / 2)
		{
			while (stack->b->index != index)
				rb(&stack, 1);
		}
		else
		{
			while (stack->b->index != index)
				rrb(&stack, 1);
		}
		pa(&stack, 1);
		--n;
	}
}

static int	pos_in_list(int index, t_node *list)
{
	int		i;
	t_node	*tmp;

	tmp = list;
	i = 0;
	while (tmp)
	{
		if (tmp->index == index)
			return (i);
		++i;
		tmp = tmp->next;
	}
	return (-1);
}

static int	max_index(t_node *list)
{
	int		max;
	int		index;
	t_node	*tmp;

	tmp = list;
	index = tmp->index;
	max = tmp->val;
	while (tmp)
	{
		if (max < tmp->val)
		{
			index = tmp->index;
			max = tmp->val;
		}
		tmp = tmp->next;
	}
	return (index);
}

int	find_min_position(t_node *stack)
{
	t_node	*tmp;
	int		pos;
	int		min;
	int		i;

	tmp = stack;
	min = tmp->val;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->val < min)
		{
			min = tmp->val;
			pos = i;
		}
		tmp = tmp->next;
		++i;
	}
	return (pos);
}

void	repeat_until(void (*func)(t_stack **, int), t_stack **stack, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		func(stack, 1);
		++i;
	}
}
