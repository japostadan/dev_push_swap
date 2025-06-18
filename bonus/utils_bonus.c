/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japostad <japostad@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:31:22 by japostad          #+#    #+#             */
/*   Updated: 2025/06/12 11:31:23 by japostad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	exec_instruction(char *inst, t_stack *stack)
{
	if (!ft_strcmp("pa\n", inst))
		return (pa(&stack, 0), 1);
	else if (!ft_strcmp("pb\n", inst))
		return (pb(&stack, 0), 1);
	else if (!ft_strcmp("ra\n", inst))
		return (ra(&stack, 0), 1);
	else if (!ft_strcmp("rb\n", inst))
		return (rb(&stack, 0), 1);
	else if (!ft_strcmp("rr\n", inst))
		return (rr(&stack, 0), 1);
	else if (!ft_strcmp("rra\n", inst))
		return (rra(&stack, 0), 1);
	else if (!ft_strcmp("rrb\n", inst))
		return (rrb(&stack, 0), 1);
	else if (!ft_strcmp("rrr\n", inst))
		return (rrr(&stack, 0), 1);
	else if (!ft_strcmp("sa\n", inst))
		return (sa(&stack, 0), 1);
	else if (!ft_strcmp("sb\n", inst))
		return (sb(&stack, 0), 1);
	else if (!ft_strcmp("ss\n", inst))
		return (ss(&stack, 0), 1);
	else
		return (0);
}

int	is_stack_sorted(t_stack	*stack)
{
	char	*instruction;
	t_node	*tmp;

	tmp = stack->a;
	while (1)
	{
		instruction = get_next_line(STDIN_FILENO);
		if (!instruction)
			break ;
		if (!exec_instruction(instruction, stack))
		{
			get_next_line(-1);
			free(instruction);
			return (-1);
		}
		free(instruction);
	}
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
