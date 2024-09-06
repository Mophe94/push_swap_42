/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:04:54 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/06 22:22:51 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

char	*parse_arg_str(char **argv)
{
	int		i;
	char	*str;
	char	*tmp;
	char	*arg;

	str = ft_strdup("");
	if (!str)
		return (0);
	i = 1;
	while (argv[i])
	{
		arg = ft_strdup(argv[i]);
		tmp = ft_strjoin_free_s1(arg, " ");
		str = ft_strjoin_free_s1(str, tmp);
		free(tmp);
		i++;
	}
	return (str);
}

int	ft_check_error(char *str)
{
	char	**tab_tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab_tmp = ft_split(str, ' ');
	while (tab_tmp[i])
	{
		j = 0;
		if ((ft_atol(tab_tmp[i]) > INT_MAX) || (ft_atol(tab_tmp[i]) < INT_MIN))
			return (0);
		while (tab_tmp[i][j])
		{
			if ((tab_tmp[i][j] == '-') || (tab_tmp[i][j] == '+')
				|| (tab_tmp[i][j] == '"'))
				j++;
			if (!ft_isdigit(tab_tmp[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_double(char *str)
{
	int		i;
	int		j;
	char	**tab_tmp;

	i = 0;
	tab_tmp = ft_split(str, ' ');
	while (tab_tmp[i])
	{
		j = i + 1;
		while (tab_tmp[j])
		{
			if (ft_atol(tab_tmp[i]) == ft_atol(tab_tmp[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	string_into_stack(char **tab, t_stack **stack)
{
	int i;
	char *clean_str;
	char **clean_tab;

	i = 0;
	clean_str = parse_arg_str(tab);
	clean_tab = ft_split(clean_str, ' ');
	while (clean_tab[i])
	{
		stack_new_circular(stack, (void *)(long)ft_atol(clean_tab[i]));
		i++;
	}
	free(clean_str);
	ft_free(clean_tab);
}