/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:09:53 by dbajeux           #+#    #+#             */
/*   Updated: 2024/08/20 17:32:42 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa_moves(t_list **a_list)
{
	t_list	*first;
	t_list	*second;
	int		tmp_index;
	t_list	*tmp;

	if (*a_list == NULL)
		return;
	first = *a_list;
	second = (*a_list)->next;
	tmp = first->next;
	first->next = second->next;
	second->next = tmp;
	*a_list = second;
	tmp_index = first->index;
	first->index = second->index;
	second->index = tmp_index;
    ft_printf("SA\n");
}

void	sb_moves(t_list **b_list)
{
	t_list *first;
	t_list *second;
	int tmp_index;
	t_list *tmp;

	if (*b_list == NULL)
		return;
	first = *b_list;
	second = (*b_list)->next;
	tmp = first->next;
	first->next = second->next;
	second->next = tmp;
	*b_list = second;
	tmp_index = first->index;
	first->index = second->index;
	second->index = tmp_index;
    ft_printf("SB\n");
}

void ss_moves(t_list **a_list, t_list **b_list)
{
    sa_moves(a_list);
    sb_moves(b_list);
    ft_printf("SS\n");
}