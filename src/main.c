/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:11:46 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/04 22:30:15 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc == 1)
		exit(1);
	else
	{
		if (!ft_check_error(parse_arg_str(argv))
			|| !ft_check_double(parse_arg_str(argv)))
			ft_print_exit();
		string_into_list(argv, &list_a);
 		pb_move(&list_a, &list_b);
		pb_move(&list_a, &list_b);
		pb_move(&list_a, &list_b);
		pb_move(&list_a, &list_b);
		print_lst(list_a);
		print_lst(list_b);
		ss_move(&list_a, &list_b);
		print_lst(list_a);
		print_lst(list_b);
		rr_move(&list_a, &list_b);
		print_lst(list_a);
		print_lst(list_b);
		rrr_move(&list_a, &list_b);
		print_lst(list_a);
		print_lst(list_b);
	}
	return (0);
}
