/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:48:08 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/06 22:20:32 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ra_move(t_stack **a_stack)
{
	if (!a_stack)
		return ;
	stack_rotate(a_stack);
	ft_printf("ra\n");
}
void	rb_move(t_stack **b_stack)
{
	if (!b_stack)
		return ;
	stack_rotate(b_stack);
	ft_printf("rb\n");
}
void	rr_move(t_stack **a_stack, t_stack **b_stack)
{
	stack_rotate(a_stack);
	stack_rotate(b_stack);
	ft_printf("rr\n");
}