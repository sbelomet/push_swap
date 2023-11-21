/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:13:14 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/21 10:29:52 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atoi(char *str)
{
	int				i;
	int				neg;
	long long int	res;

	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * neg);
}

t_stack	*ft_smallest_node(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*smallest;
	int		i;
	int		len;

	tmp = *head;
	smallest = *head;
	i = 0;
	len = ft_stack_len(*head);
	while (i < len)
	{
		if (tmp->value < tmp->after->value && tmp->value <= smallest->value)
			smallest = tmp;
		tmp = tmp->after;
		i++;
	}
	return (smallest);
}

int	check_max(char **tab)
{
	int				i;
	long long int	n;

	i = 0;
	while (tab[i])
	{
		n = ft_atoi(tab[i]);
		if (n > 2147483647 || n < -2147483648)
			return (0);
		i++;
	}
	return (1);
}
