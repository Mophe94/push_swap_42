/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:53:15 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/04 19:52:35 by dbajeux          ###   ########.fr       */
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