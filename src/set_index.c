/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japostad <japostad@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:15:36 by japostad          #+#    #+#             */
/*   Updated: 2025/06/18 11:42:30 by japostad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	assign_indexes(t_node *head)
{
	int		index;
	t_node	*current;
	t_node	*temp_head;

	temp_head = head;
	while (head)
	{
		current = temp_head;
		index = 0;
		while (current)
		{
			if (head->val > current->val)
				index++;
			current = current->next;
		}
		head->index = index;
		head = head->next;
	}
}
