/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japostad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:23:57 by japostad          #+#    #+#             */
/*   Updated: 2025/06/18 11:08:46 by japostad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	chunk_size(int nb);

void	bucket_sort(t_stack *stack, int len)
{
	int	counter;
	int	n;

	n = chunk_size(len);
	counter = 0;
	stack->b = NULL;
	while (stack->a)
	{
		if (stack->a->index <= counter)
		{
			pb(&stack, 1);
			rb(&stack, 1);
			++counter;
		}
		else if (stack->a->index <= (counter + n))
		{
			pb(&stack, 1);
			++counter;
		}
		else
			ra(&stack, 1);
	}
	sort_max(stack, len);
}

static int	chunk_size(int nb)
{
	int	sqrt;
	int	log;
	int	result;

	sqrt = 1;
	if (nb <= sqrt)
		return (sqrt);
	while (sqrt * sqrt < nb)
		++sqrt;
	log = 0;
	result = 1;
	while (result < nb)
	{
		result *= 2;
		++log;
	}
	return (sqrt + log - 1);
}
