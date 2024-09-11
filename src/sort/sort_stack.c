/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:46:32 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/11 15:12:14 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"


void	sort_for_three(t_stack **stack_a)
{
	t_stack	*max_node;

	if (stack_get_size(stack_a) != 3)
		return ;
	max_node = stack_find_max_content(stack_a);
	if ((*stack_a) == max_node)
		ra_move(stack_a);
	else if ((*stack_a)->next == max_node)
		rra_move(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa_move(stack_a);
}
void move_b_to_a(t_stack **stack_a,t_stack **stack_b)
{
	check_top_stack((*stack_b)->target_node,stack_a,'a');
	pa_move(stack_a, stack_b);
}
void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = stack_set_cheapest(stack_a);
	if (cheapest->above_median == 1 && cheapest->target_node->above_median == 1)
	{
		while (*stack_a != cheapest && *stack_b != cheapest->target_node)
			rr_move(stack_a, stack_b);
		stack_init_index(stack_a);
		stack_init_index(stack_b);
	}
	else if (cheapest->above_median == 0
		&& cheapest->target_node->above_median == 0)
	{
		while (*stack_a != cheapest && *stack_b != cheapest->target_node)
			rrr_move(stack_a, stack_b);
		stack_init_index(stack_a);
		stack_init_index(stack_b);
	}
	check_top_stack(cheapest, stack_a, 'a');
	check_top_stack(cheapest->target_node, stack_b, 'b');
	stack_init_index(stack_a);
	stack_init_index(stack_b);
	pb_move(stack_a, stack_b);
}
void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_get_size(stack_a) > 3)
		pb_move(stack_a, stack_b);
	if (stack_get_size(stack_a) > 3)
		pb_move(stack_a, stack_b);
	while (stack_get_size(stack_a) > 3)
	{
		init_stack_a(stack_a, stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_for_three(stack_a);
	while (*stack_b)
	{
		init_stack_b(stack_a, stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	stack_init_index(stack_a);
	check_min_on_top(stack_a);
}
