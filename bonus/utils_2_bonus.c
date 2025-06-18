/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japostad <japostad@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:30:35 by japostad          #+#    #+#             */
/*   Updated: 2025/06/12 11:30:36 by japostad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_error(char **split)
{
	if (split)
		free_split(&split);
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_split(char ***split)
{
	int	i;

	if (!*split)
		return ;
	i = -1;
	while ((*split)[++i])
		free((*split)[i]);
	free(*split);
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*next;

	tmp = stack->a;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	tmp = stack->b;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(stack);
}

void	print_operation(char *operation)
{
	write (1, operation, ft_strlen(operation));
}

char	**split_args(int argc, char **argv)
{
	char	*join;
	char	**split;

	join = join_args(argc, argv);
	split = ft_split(join);
	free(join);
	return (split);
}
