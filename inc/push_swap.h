/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:08:51 by dbajeux           #+#    #+#             */
/*   Updated: 2024/08/28 13:49:39 by dbajeux          ###   ########.fr       */
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

void	string_into_list(char *str, t_list **list_a);
void	ft_print_exit(void);
int		ft_count_tab_size(char **tab_str);
long	ft_atol(const char *str);
int		ft_check_error(char *str);
int		ft_check_double(char *argv);
void	sa_moves(t_list **a_list);
void	ft_print_list(t_list **list_a);
t_list	*found_head(t_list **list);
void pa_moves(t_list **a_list,t_list **b_list);
void	ft_reset_index(t_list **list);
void	pb_moves(t_list **a_list, t_list **b_list);
char *parse_arg_str(char **argv);
#endif
