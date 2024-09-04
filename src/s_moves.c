/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:09:53 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/04 17:05:06 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa_move(t_list **a_list)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (*a_list == NULL || (*a_list)->next == NULL)
		return ;
	first = *a_list;
	second = first->next;
	last = lst_found_last_node(a_list);
	first->next = second->next;
	second->next = first;
	last->next = second;
	*a_list = second;
	ft_printf("sa\n");
}

void	sb_move(t_list **b_list)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (*b_list == NULL)
		return ;
	first = *b_list;
	second = first->next;
	last = lst_found_last_node(b_list);
	first->next = second->next;
	second->next = first;
	last->next = second;
	*b_list = second;
	ft_printf("sb\n");
}

void	ss_move(t_list **a_list, t_list **b_list)
{
	sa_move(a_list);
	sb_move(b_list);
	ft_printf("ss\n");
}
