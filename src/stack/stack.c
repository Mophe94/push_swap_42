/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:13:23 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/06 18:19:13 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack	*stack_set_cheapest(t_stack **stack)
{
	t_stack	*current;
	t_stack	*lower;

	current = *stack;
	lower = *stack;
	while (1) 
	{
		if (current->push_cost < lower->push_cost)
			lower = current;
		current = current->next;
		if (current == *stack) 
			break;	
	}
	lower->cheapest = 1;
	return (lower);
}
t_stack	*stack_find_max_content(t_stack **stack)
{
	t_stack	*current;
	t_stack	*node_max;
	long	best_match;

	best_match = LONG_MIN;
	current = *stack;
	while (1)
	{
		if ((long)current->content > best_match)
		{
			best_match = (long)current->content;
			node_max = current;
		}
		current = current->next;
		if (current == *stack) 
			break;
	}
	return (node_max);
}
t_stack *stack_find_min_content(t_stack **stack)
{
	t_stack *current;
	t_stack *node_min;
	long best_match;

	best_match = LONG_MAX;
	current = *stack;
	while (1) 
	{
		if ((long)current->content < best_match) 
		{
			best_match =(long)current->content;
			node_min = current;
		}
		current = current->next;
		if (current == *stack)
			break;
	}
	return (node_min);
}

int	stack_get_size(t_stack **stack)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = *stack;
	while (current->next != *stack)
	{
		i++;
		current = current->next;
	}
	i++;
	return (i);
}

t_stack	*stack_find_last_node(t_stack **head)
{
	t_stack	*last;

	last = *head;
	while (last->next != *head)
		last = last->next;
	return (last);
}
void	stack_new_circular(t_stack **head, void *content)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		ft_print_exit();
	new_node->content = content;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = *head;
	}
	else
	{
		last = *head;
		while (last->next != *head)
			last = last->next;
		last->next = new_node;
		new_node->next = *head;
	}
}
void	print_stack_a(t_stack *head)
{
	t_stack	*current;

	if (!head)
	{
		ft_printf("La stacke est vide.\n");
		return ;
	}
	current = head;
	ft_printf("A stack\n");
	while (1)
	{
		ft_printf("<Content: %d // index: %d // median : %d // target_content %d // push_cost: %d\n", (int)(long)current->content, current->index,
			current->above_median, (int)(long)current->target_node->content,
			current->push_cost,stack_set_cheapest(&head));
		current = current->next;
		if (current == head) 
			break;
	}
	ft_printf("___________________________\n");
}
void	print_stack_b(t_stack *head)
{
	t_stack	*current;

	if (!head)
	{
		ft_printf("La stacke est vide.\n");
		return ;
	}
	current = head;
	ft_printf("B stack\n");
	while (1)
	{
		ft_printf("<Content: %d // index: %d // median : %d\n",
			(int)(long)current->content, current->index, current->above_median);
		current = current->next;
		if (current == head)
			break;
	}
	ft_printf("___________________________\n");
}
