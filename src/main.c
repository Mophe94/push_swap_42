/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:11:46 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/06 22:06:30 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit(1);
	else
	{
		if (!ft_check_error(parse_arg_str(argv))
			|| !ft_check_double(parse_arg_str(argv)))
			ft_print_exit();
		string_into_stack(argv, &stack_a);
 		pb_move(&stack_a, &stack_b); 
 		pb_move(&stack_a, &stack_b); 
 		pb_move(&stack_a, &stack_b); 
 		pb_move(&stack_a, &stack_b); 
		stack_init_target_node_a(&stack_a, &stack_b);
		print_stack(stack_a);
/*		pb_move(&stack_a, &stack_b);
		pb_move(&stack_a, &stack_b);
		pb_move(&stack_a, &stack_b);
		stack_init_index(&stack_a);
		stack_init_index(&stack_b);
		stack_init_median(&stack_a);
		stack_init_median(&stack_b);
		print_stack(stack_a);
		print_stack(stack_b);
		int len_a = stack_get_size(&stack_a);
		int len_b = stack_get_size(&stack_b);
		ft_printf("<%d>", len_a);
		ft_printf("<%d>", len_b);  */
		
	}
	return (0);
}
