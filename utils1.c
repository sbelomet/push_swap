/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:08:06 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/07 15:15:27 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	is_numerical(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '+' || s[i] == '-'
		|| (s[i] >= '0' && s[i] <= '9') || (s[i] > 8 && s[i] < 14))
	{	
		if ((s[i] == '-' || s[i] == '+')
			&& !(s[i + 1] >= '0' && s[i + 1] <= '9'))
			return (0);
		i++;
	}
	printf("|%s|\n", s);
	if (i != ft_strlen(s))
		return (0);
	return (1);
}

char	**ft_join_args(char **av)
{
	char	*tmp1;
	char	*tmp2;
	char	**res;
	int		i;

	i = 1;
	tmp1 = ft_strdup(" ");
	while (av[i])
	{
		tmp2 = ft_strjoin(tmp1, av[i]);
		free(tmp1);
		tmp1 = ft_strjoin(tmp2, " \0");
		free(tmp2);
		i++;
	}
	res = ft_split(tmp1, ' ');
	printf("|%s|\n", tmp1);
	free(tmp1);
	return (res);
}
