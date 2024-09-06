/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:49:16 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/06 22:20:29 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rra_move(t_stack **a_stack)
{
	stack_reverse_rotate(a_stack);
	ft_printf("rra\n");
}
void	rrb_move(t_stack **b_stack)
{
	stack_reverse_rotate(b_stack);
	ft_printf("rrb\n");
}
void	rrr_move(t_stack **a_stack, t_stack **b_stack)
{
	stack_reverse_rotate(a_stack);
	stack_reverse_rotate(b_stack);
	ft_printf("rrr\n");
}