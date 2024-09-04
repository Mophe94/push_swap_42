/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:53:15 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/04 22:32:34 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	remove_first_node(t_list **list)
{
	t_list	*last;

	if ((*list)->next == *list)
	{
		*list = NULL;
	}
	else
	{
		last = lst_found_last_node(list);
		*list = (*list)->next;
		last->next = *list;
	}
}
void lst_swap(t_list **list)
{
		t_list	*first;
	t_list	*second;
	t_list	*last;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	first = *list;
	second = first->next;
	last = lst_found_last_node(list);
	first->next = second->next;
	second->next = first;
	last->next = second;
	*list = second;
}
void	lst_rotate(t_list **list)
{
	if (!list)
		return ;
	*list = (*list)->next;
}
void	lst_reverse_rotate(t_list **list)
{
	t_list *last;

	if (!*list || (*list)->next == *list)
		return ;
	last = *list;
	while (last->next != *list)
		last = last->next;
	*list = last;
}