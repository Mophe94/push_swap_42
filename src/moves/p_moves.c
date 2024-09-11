/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:23:34 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/09 13:32:05 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	pa_move(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*element_to_push;
	t_stack	*last;

	if (*b_stack == NULL)
		return ;
	element_to_push = *b_stack;
	remove_first_node(b_stack);
	if (!(*a_stack))
	{
		element_to_push->next = element_to_push;
		*a_stack = element_to_push;
	}
	else
	{
		last = stack_find_last_node(a_stack);
		element_to_push->next = *a_stack;
		last->next = element_to_push;
		*a_stack = element_to_push;
	}
	ft_printf("pa\n");
}
void	pb_move(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*element_to_push;
	t_stack	*last;

	if (*a_stack == NULL)
		return ;
	element_to_push = *a_stack;
	remove_first_node(a_stack);
	if (!(*b_stack))
	{
		element_to_push->next = element_to_push;
		*b_stack = element_to_push;
	}
	else
	{
		last = stack_find_last_node(b_stack);
		element_to_push->next = *b_stack;
		last->next = element_to_push;
		*b_stack = element_to_push;
	}
	ft_printf("pb\n");
}
