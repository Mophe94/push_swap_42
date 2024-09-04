/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:08:51 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/04 22:33:58 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/*                                 INCLUDE                                    */
/* ************************************************************************** */

# include "../inc/libft/inc/libft.h"

/* ************************************************************************** */
/*                                FUNCTION                                    */
/* ************************************************************************** */

// check arg
int		ft_check_error(char *str);
int		ft_check_double(char *argv);

// parsing
void	string_into_list(char **tab, t_list **list);
char	*parse_arg_str(char **argv);

// list
void	lst_new_circular(t_list **head, void *content);
t_list	*lst_found_last_node(t_list **head);
void	print_lst(t_list *head);

// moove
void	sa_move(t_list **a_list);
void	sb_move(t_list **b_list);
void	ss_move(t_list **a_list, t_list **b_list);
void	pa_move(t_list **a_list, t_list **b_list);
void	pb_move(t_list **a_list, t_list **b_list);
void	ra_move(t_list **a_list);
void	rb_move(t_list **b_list);
void	rr_move(t_list **a_list, t_list **b_list);
void	rra_move(t_list **a_list);
void	rrb_move(t_list **b_list);
void	rrr_move(t_list **a_list, t_list **b_list);

// utils moves
void	remove_first_node(t_list **list);
void	lst_rotate(t_list **list);
void	lst_reverse_rotate(t_list **list);
void	lst_swap(t_list **list);

// utils
void	ft_print_exit(void);
long	ft_atol(const char *str);
char	*ft_strjoin_free_s1(char *s1, char *s2);
#endif
