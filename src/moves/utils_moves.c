/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:53:15 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/06 22:20:15 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	remove_first_node(t_stack **stack)
{
	t_stack	*last;

	if ((*stack)->next == *stack)
	{
		*stack = NULL;
	}
	else
	{
		last = stack_found_last_node(stack);
		*stack = (*stack)->next;
		last->next = *stack;
	}
}
void stack_swap(t_stack **stack)
{
		t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	last = stack_found_last_node(stack);
	first->next = second->next;
	second->next = first;
	last->next = second;
	*stack = second;
}
void	stack_rotate(t_stack **stack)
{
	if (!stack)
		return ;
	*stack = (*stack)->next;
}
void	stack_reverse_rotate(t_stack **stack)
{
	t_stack *last;

	if (!*stack || (*stack)->next == *stack)
		return ;
	last = *stack;
	while (last->next != *stack)
		last = last->next;
	*stack = last;
}