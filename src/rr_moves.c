/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:49:16 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/04 16:54:37 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra_move(t_list **a_list)
{
	lst_reverse_rotate(a_list);
	ft_printf("rra\n");
}
void	rrb_move(t_list **b_list)
{
	lst_reverse_rotate(b_list);
	ft_printf("rrb\n");
}
void	rrr_move(t_list **a_list, t_list **b_list)
{
	rra_move(a_list);
	rrb_move(b_list);
	ft_printf("rrr\n");
}