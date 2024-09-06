/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:51:25 by dbajeux           #+#    #+#             */
/*   Updated: 2024/09/06 22:22:43 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_print_exit(void)
{
	ft_printf("Error");
	exit(1);
}

long	ft_atol(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

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
