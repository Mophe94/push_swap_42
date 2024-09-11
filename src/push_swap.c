/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:19:05 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/10 21:21:16 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void push_swap(t_stack **stack_a,t_stack **stack_b)
{
    if(stack_get_size(stack_a) == 2)
        sa_move(stack_a);
    else if (stack_get_size(stack_a) == 3)
        sort_for_three(stack_a);
    else if (stack_get_size(stack_a) > 3)
        sort_stack(stack_a,stack_b);
}