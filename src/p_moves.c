/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:23:34 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/04 16:53:44 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pa_move(t_list **a_list, t_list **b_list)
{
	t_list	*element_to_push;
	t_list	*last;

	if (*b_list == NULL)
		return ;
	element_to_push = *b_list;
	remove_first_node(b_list);
	if (!(*a_list))
	{
		element_to_push->next = element_to_push;
		*a_list = element_to_push;
	}
	else
	{
		last = lst_found_last_node(a_list);
		element_to_push->next = *a_list;
		last->next = element_to_push;
		*a_list = element_to_push;
	}
	ft_printf("pa\n");
}
void	pb_move(t_list **a_list, t_list **b_list)
{
	t_list	*element_to_push;
	t_list	*last;

	if (*a_list == NULL)
		return ;
	element_to_push = *a_list;
	remove_first_node(a_list);
	if (!(*b_list))
	{
		element_to_push->next = element_to_push;
		*b_list = element_to_push;
	}
	else
	{
		last = lst_found_last_node(b_list);
		element_to_push->next = *b_list;
		last->next = element_to_push;
		*b_list = element_to_push;
	}
	ft_printf("pb\n");
}
