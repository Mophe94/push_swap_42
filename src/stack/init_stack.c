/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:28:42 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/06 22:29:55 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack	*find_best_target(t_stack *node, t_stack **stack_b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;

	best_match_index = LONG_MIN;
	current_b = *stack_b;
	while (current_b->next != *stack_b)
	{
		if ((int)(long)current_b->content < (int)(long)node->content
			&& (int)(long)current_b->content > best_match_index)
		{
			best_match_index = (long)current_b->content;
			target_node = current_b;
		}
		current_b = current_b->next;
	}
    if ((int)(long)current_b->content < (int)(long)node->content
			&& (int)(long)current_b->content > best_match_index)
		{
			best_match_index = (long)current_b->content;
			target_node = current_b;
		}
	if (best_match_index == LONG_MIN)
		return (stack_find_max_content(stack_b));
	return (target_node);
}
void	stack_init_target_node_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current;
    t_stack *head;
    
    head = *stack_a;
    current = *stack_a;
    while (current->next != head )
    {
        current->target_node = find_best_target(current, stack_b);
        current = current->next;
    }
    current->target_node = find_best_target(current, stack_b);
}

void	init_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	stack_init_index(stack_a);
	stack_init_index(stack_a);
	stack_init_median(stack_a);
	stack_init_median(stack_b);

}