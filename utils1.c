/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:08:06 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/13 13:36:05 by sbelomet         ###   ########.fr       */
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

int	is_numerical(char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] == ' ' || tab[i][j] == '+' || tab[i][j] == '-'
			|| (tab[i][j] >= '0' && tab[i][j] <= '9'))
		{	
			if ((tab[i][j] == '-' || tab[i][j] == '+')
				&& !(tab[i][j + 1] >= '0' && tab[i][j + 1] <= '9'))
				return (0);
			j++;
		}
		if (j != ft_strlen(tab[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_doubles(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (!(ft_strcmp(tab[i], tab[j])))
				return (0);
			j++;
		}
		i++;
	}
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
	free(tmp1);
	if (!check_doubles(res))
	{
		ft_free_array(res);
		return (NULL);
	}
	return (res);
}

int	is_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (!(tmp->is_last))
	{
		if (tmp->value < tmp->after->value)
			tmp = tmp->after;
		else
			return (0);
	}
	return (1);
}
