/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:08:51 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/06 22:28:22 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/*                                 INCLUDE                                    */
/* ************************************************************************** */

# include "../inc/libft/inc/libft.h"

/* ************************************************************************** */
/*                                 STRUCT                                     */
/* ************************************************************************** */

typedef struct s_stack
{
	void			*content;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
}					t_stack;

/* ************************************************************************** */
/*                                FUNCTION                                    */
/* ************************************************************************** */

// check arg
int					ft_check_error(char *str);
int					ft_check_double(char *argv);

// parsing
void				string_into_stack(char **tab, t_stack **stack);
char				*parse_arg_str(char **argv);

// check parsing utils
void				ft_print_exit(void);
long				ft_atol(const char *str);
char				*ft_strjoin_free_s1(char *s1, char *s2);

// stack
void				stack_new_circular(t_stack **head, void *content);
void				stack_init_index(t_stack **stack);
void				stack_init_median(t_stack **stack);
void				stack_init_target_node_a(t_stack **stack_a,
						t_stack **stack_b);
t_stack				*stack_found_last_node(t_stack **head);
int					stack_get_size(t_stack **stack);
t_stack				*stack_find_max_content(t_stack **stack);
void				print_stack(t_stack *head);

// moove
void				sa_move(t_stack **a_stack);
void				sb_move(t_stack **b_stack);
void				ss_move(t_stack **a_stack, t_stack **b_stack);
void				pa_move(t_stack **a_stack, t_stack **b_stack);
void				pb_move(t_stack **a_stack, t_stack **b_stack);
void				ra_move(t_stack **a_stack);
void				rb_move(t_stack **b_stack);
void				rr_move(t_stack **a_stack, t_stack **b_stack);
void				rra_move(t_stack **a_stack);
void				rrb_move(t_stack **b_stack);
void				rrr_move(t_stack **a_stack, t_stack **b_stack);

// utils moves
void				remove_first_node(t_stack **stack);
void				stack_rotate(t_stack **stack);
void				stack_reverse_rotate(t_stack **stack);
void				stack_swap(t_stack **stack);

#endif
