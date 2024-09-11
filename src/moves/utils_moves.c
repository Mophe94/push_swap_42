/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:53:15 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/10 20:38:18 by dbajeux          ###   ########.fr       */
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
		last = stack_find_last_node(stack);
		*stack = (*stack)->next;
		last->next = *stack;
	}
}
void	stack_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*prev;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	prev = first->next;
	last = stack_find_last_node(stack);
	first->next = prev->next;
	prev->next = first;
	last->next = prev;
	*stack = prev;
}
void	stack_rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;
	
	if (!stack || (*stack)->next == *stack)
		return ;

	first = *stack;
	last = *stack;
	while (last->next != *stack) 
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = *stack;
}
void	stack_reverse_rotate(t_stack **stack)
{
  	t_stack *prev;
	t_stack *last;
	
	if (!stack || (*stack)->next == *stack)
		return ;

	prev = NULL;
	last = *stack;
	while (last->next != *stack) 
	{
		prev = last;
		last = last->next;
		
	}
	prev = last;
	prev->next = *stack;
	last->next = *stack;
	*stack = last;
}