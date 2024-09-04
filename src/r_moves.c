/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:48:08 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/04 17:07:29 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra_move(t_list **a_list)
{
	if (!a_list)
		return ;
	lst_rotate(a_list);
	ft_printf("ra\n");
}
void	rb_move(t_list **b_list)
{
	if (!b_list)
		return ;
	lst_rotate(b_list);
	ft_printf("rb\n");
}
void	rr_move(t_list **a_list, t_list **b_list)
{
	ra_move(a_list);
	rb_move(b_list);
	ft_printf("rr\n");
}