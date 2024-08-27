/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:11:46 by dbajeux           #+#    #+#             */
/*   Updated: 2024/08/27 14:45:43 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc//push_swap.h"
#include <stdio.h>

void	string_into_list(char *str, t_list **list_a)
{
	char	**clean_str;
	int		i;
	t_list	*new_node;

	i = -1;
	clean_str = ft_split(str, ' ');
	while (clean_str[++i])
	{
		new_node = ft_lstnew((void *)(long)ft_atoi(clean_str[i]));
		new_node->index = i + 1;
		if (!new_node)
		{
			ft_free(clean_str);
			return ;
		}
		if (*list_a == NULL)
			*list_a = new_node;
		else
			ft_lstadd_back(list_a, new_node);
	}
	new_node->next = list_a[0];
	ft_free(clean_str);
}

int	main(int argc, char **argv)
{
	t_list *list_a;
	t_list *list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc == 1)
		exit(1);
	else
	{
		if (!ft_check_error(argv[1]) || !ft_check_double(argv[1]))
			ft_print_exit();
		string_into_list(argv[1], &list_a);
		ft_print_list(&list_a);
		pb_moves(&list_a, &list_b);
		//sa_moves(&list_a);
		ft_print_list(&list_a);
	/* 	printf("index : <%d> // content : <%d>\n", list_a->index,
			(int)(long)list_a->content);
		printf("index : <%d> // content : <%d>\n", list_a->next->index,
			(int)(long)list_a->next->index);
		printf("index : <%d> // content : <%d>\n", list_a->next->next->index,
			(int)(long)list_a->next->next->index); */
		// fonction push_swap
	}
	return (0);
}