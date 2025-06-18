/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japostad <japostad@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:14:24 by japostad          #+#    #+#             */
/*   Updated: 2025/06/18 11:19:07 by japostad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

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
char	*join_args(int argc, char **argv);
char	**split_args(int argc, char **argv);
t_stack	*init_stack(char **split);

void	ft_error(char **split);
void	free_split(char ***split);
void	free_stack(t_stack *stack);
void	print_operation(char *operation);

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

/*sort utils*/
int		find_min_position(t_node *stack);
void	sort_max(t_stack *stack, int n);
void	repeat_until(void (*func)(t_stack **, int), t_stack **stack, int count);

/*sorting*/
void	sort_2(t_stack *stack);
void	sort_3(t_stack *stack);
void	sort_4(t_stack *stack);
void	sort_5(t_stack **stack);
void	assign_indexes(t_node *head);
void	bucket_sort(t_stack *stack, int len);

#endif
