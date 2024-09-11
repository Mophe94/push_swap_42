/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:31:53 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/11 14:26:43 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack	*find_best_target_a(t_stack *node, t_stack **stack_b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match;

	best_match = LONG_MIN;
	current_b = *stack_b;
	while (1)
	{
		if ((int)(long)current_b->content < (int)(long)node->content
			&& (int)(long)current_b->content > best_match)
		{
			best_match = (long)current_b->content;
			target_node = current_b;
		}
		current_b = current_b->next;
		if (current_b == *stack_b)
			break ;
	}
	if (best_match == LONG_MIN)
		return (stack_find_max_content(stack_b));
	return (target_node);
}
void	stack_init_target_node_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;

	current = *stack_a;
	while (1)
	{
		current->target_node = find_best_target_a(current, stack_b);
		current = current->next;
		if (current == *stack_a)
			break ;
	}
}
t_stack	*find_best_target_b(t_stack *node, t_stack **stack_a)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match;

	current_a = *stack_a;
	best_match = LONG_MAX;
	while (1)
	{
		if ((int)(long)current_a->content > (int)(long)node->content
			&& (int)(long)current_a->content < best_match)
		{
			best_match = (long)current_a->content;
			target_node = current_a;
		}
		current_a = current_a->next;
		if (current_a == *stack_a)
			break ;
	}
	if (best_match == LONG_MAX)
		return (stack_find_min_content(stack_a));
	return (target_node);
	;
}

void	stack_init_target_node_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *current_b;

	current_b = *stack_b;
	while (1)
	{
		current_b->target_node = find_best_target_b(current_b, stack_a);
		current_b = current_b->next;
		if (current_b == *stack_b)
			break ;
	}
	stack_init_index(stack_a);
	stack_init_index(stack_b);
}