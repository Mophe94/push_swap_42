/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:09:53 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/04 22:34:57 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa_move(t_list **a_list)
{
	lst_swap(a_list);
	ft_printf("sa\n");
}

void	sb_move(t_list **b_list)
{
	lst_swap(b_list);
	ft_printf("sb\n");
}

void	ss_move(t_list **a_list, t_list **b_list)
{
	lst_swap(a_list);
	lst_swap(b_list);
	ft_printf("ss\n");
}
