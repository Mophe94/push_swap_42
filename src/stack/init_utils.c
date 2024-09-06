/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:31:53 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/06 22:34:57 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	stack_init_index(t_stack **stack)
{
	int		i;
	t_stack	*current;

	i = 1;
	current = *stack;
	while (current->next != *stack)
	{
		current->index = i;
		i++;
		current = current->next;
	}
	current->index = i;
}
void	stack_init_median(t_stack **stack)
{
	int len_stack;
	t_stack *current;

	len_stack = stack_get_size(stack);
	current = *stack;
	while (current->next != *stack)
	{
		if (current->index < (len_stack / 2))
			current->above_median = 0;
		else
			current->above_median = 1;
		current = current->next;
	}
	if (current->index < (len_stack / 2))
		current->above_median = 0;
	else
		current->above_median = 1;
	current = current->next;
}