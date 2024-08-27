/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:04:54 by dbajeux           #+#    #+#             */
/*   Updated: 2024/08/27 15:03:02 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
			if ((tab_tmp[i][j] == '-') || (tab_tmp[i][j] == '+'))
				j++;
			if (!ft_isdigit(tab_tmp[i][j]))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_double(char *str)
{
	int i;
	int j;
	char **tab_tmp;

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