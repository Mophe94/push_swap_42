/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:51:25 by dbajeux           #+#    #+#             */
/*   Updated: 2024/08/28 14:51:54 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>


// a ameliorer la fonction ne fonctionne pas correctement car je modifie l'emplacement des adresse dans ma liste en modifiant le content
/* void	ft_print_list(t_list **list_a)
{
	t_list	*current;
	int n;

	n = 0;
	current = *list_a;
	while (n < 8)
	{
		printf(" [node : <%d> content : <%d> next : <%d>] \n", current->index, (int)(long)current->content,current->next->index);
		current = current->next;
		n++;
	}
}

void	ft_reset_index(t_list **list)
{
	t_list	*current;
	int		i;
	int		check;

	current = *list;
	i = 1;
	check = 1;
	while ((current->index != 1) || check == 1)
	{
		current->index = i;
		current = current->next;
		i++;
		if (current->index == 1)
			check = 0;
	}
} */

/* t_list *found_head(t_list **list)
{
	t_list *current;

	current = *list;
	while (current->index != 1) 
		current = current->next;
	return (current);
}*/
void	ft_print_exit(void)
{
	printf("Error");
	exit(1);
} 

/* int	ft_count_tab_size(char **tab_str)
{
	int	i;

	while (tab_str[i])
		i++;
	return (i);
}  */

long	ft_atol(const char *str)
{
	int i;
	int sign;
	unsigned long long result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
