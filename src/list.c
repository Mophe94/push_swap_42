/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:13:23 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/04 19:53:04 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	*lst_found_last_node(t_list **head)
{
	t_list	*last;

	last = *head;
	while (last->next != *head)
		last = last->next;
	return (last);
}
void	lst_new_circular(t_list **head, void *content)
{
	t_list	*new_node;
	t_list	*last;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		ft_print_exit();
	new_node->content = content;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = *head;
	}
	else
	{
		last = *head;
		while (last->next != *head)
			last = last->next;
		last->next = new_node;
		new_node->next = *head;
	}
}
void	print_lst(t_list *head)
{
	t_list	*current;

	if (!head)
	{
		ft_printf("La liste est vide.\n");
		return ;
	}
	current = head;
	do
	{
		ft_printf("<Contenu: %d>\n", (int)(long)current->content);
		current = current->next;
	} while (current != head);
	ft_printf("___________________________\n");
}
