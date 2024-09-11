/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:28:42 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/11 15:09:49 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	stack_init_index(t_stack **stack)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = *stack;
	if (!(*stack))
		return ;
	while (1)
	{
		current->index = i;
		i++;
		current = current->next;
		if (current == *stack)
			break ;
	}
}
void	stack_init_median(t_stack **stack)
{
	int		len_stack;
	t_stack	*current;

	len_stack = stack_get_size(stack);
	current = *stack;
	while (1)
	{
		if (current->index < (len_stack / 2))
			current->above_median = 1;
		else
			current->above_median = 0;
		current = current->next;
		if (current == *stack)
			break ;
	}
}

void	stack_init_push_cost_a(t_stack **stack_a, t_stack **stack_b)
{
	int		len_a;
	int		len_b;
	t_stack	*current_a;

	len_a = stack_get_size(stack_a);
	len_b = stack_get_size(stack_b);
	current_a = *stack_a;
	while (1)
	{
		current_a->push_cost = current_a->index;
		if (current_a->above_median == 0)
			current_a->push_cost = len_a - (current_a->index);
		if (current_a->target_node->above_median == 1)
			current_a->push_cost += current_a->target_node->index;
		else
			current_a->push_cost += len_b - current_a->target_node->index;
		current_a = current_a->next;
		if (current_a == *stack_a)
			break ;
	}
}
void	init_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	stack_init_index(stack_a);
	if (*stack_b)
	{
		stack_init_index(stack_b);
		stack_init_target_node_b(stack_a, stack_b);
	}
}
void	init_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	stack_init_index(stack_a);
	stack_init_index(stack_b);
	stack_init_median(stack_a);
	stack_init_median(stack_b);
	stack_init_target_node_a(stack_a, stack_b);
	stack_init_push_cost_a(stack_a, stack_b);
}