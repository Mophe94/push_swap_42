/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:09:53 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/06 22:20:23 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sa_move(t_stack **a_stack)
{
	stack_swap(a_stack);
	ft_printf("sa\n");
}

void	sb_move(t_stack **b_stack)
{
	stack_swap(b_stack);
	ft_printf("sb\n");
}

void	ss_move(t_stack **a_stack, t_stack **b_stack)
{
	stack_swap(a_stack);
	stack_swap(b_stack);
	ft_printf("ss\n");
}
