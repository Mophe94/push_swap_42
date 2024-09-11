/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:11:46 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/11 15:20:19 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || !argv[1][0])
		exit(1);
	else
	{
		if (!ft_check_error(parse_arg_str(argv))
			|| !ft_check_double(parse_arg_str(argv)))
			ft_print_exit();
		string_into_stack(argv, &stack_a);
		if (stack_is_sorted(&stack_a) == 1)
			exit(1);
		push_swap(&stack_a, &stack_b);
		print_stack_b(stack_a);
	}
	
	// free_stack
	return (0);
}
