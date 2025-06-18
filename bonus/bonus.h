/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japostad <japostad@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:26:10 by japostad          #+#    #+#             */
/*   Updated: 2025/06/12 11:26:16 by japostad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H

# define BONUS_H

# include "../libft/libft.h"

typedef struct s_node
{
	int				val;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
}	t_stack;

typedef struct s_line
{
	char	*join;
	char	**sp;
}	t_line;

/*push swap utils*/
int		is_valid_arg(char **str, int len);
int		stack_length(t_node *stack);
int		atoi_check(char *str);

char	*join_args(int argc, char **argv);
char	**split_args(int argc, char **argv);
t_stack	*init_stack(char **split);

void	ft_error(char **split);
void	free_split(char ***split);
void	free_stack(t_stack *stack);
void	print_operation(char *operation);

/*checker main function*/
int		is_stack_sorted(t_stack	*stack);

/*swap instructions*/
void	sa(t_stack **stack, int print);
void	sb(t_stack **stack, int print);
void	ss(t_stack **stack, int print);

/*push instructions*/
void	pa(t_stack **stack, int print);
void	pb(t_stack **stack, int print);

/*rotate instructions*/
void	ra(t_stack **stack, int print);
void	rb(t_stack **stack, int print);
void	rr(t_stack **stack, int print);

/*reverse rotate instructions*/
void	rra(t_stack **stack, int print);
void	rrb(t_stack **stack, int print);
void	rrr(t_stack **stack, int print);

#endif
