/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:16:03 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/11 14:41:44 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	check_top_stack(t_stack *cheapest_node, t_stack **stack, char c)
{
	while (cheapest_node != (*stack))
	{
		if (c == 'a')
		{
			if (cheapest_node->above_median == 1)
				ra_move(stack);
			else
				rra_move(stack);
		}
		else if (c == 'b')
		{
			if (cheapest_node->above_median == 1)
				rb_move(stack);
			else
				rrb_move(stack);
		}
	}
}
int	stack_is_sorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current->next != *stack)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}
void	check_min_on_top(t_stack **stack_a)
{
	t_stack *min;

	min = stack_find_min_content(stack_a);
	while (*stack_a != min)
	{
		if (min->above_median == 1)
			ra_move(stack_a);
		else
			rra_move(stack_a);
	}
}