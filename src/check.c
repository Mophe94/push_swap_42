/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:04:54 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/02 16:17:24 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

char	*ft_strjoin_free_s1(char *s1, char *s2)
{
	char	*str_join;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str_join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str_join)
		return (NULL);
	while (s1[i])
	{
		str_join[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str_join[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	str_join[i + ft_strlen(s1)] = '\0';
	free(s1);
	return (str_join);
}

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
	printf("<%s>", str);
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
