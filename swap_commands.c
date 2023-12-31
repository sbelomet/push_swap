/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:37:10 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/10 14:12:30 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_swap(t_stack **head)
{
	t_stack	*tmp;

	if (!head || !(ft_stack_len(*head)) || ft_stack_len(*head) == 1)
		return (0);
	tmp = (*head)->after;
	tmp->after->before = *head;
	(*head)->before->after = tmp;
	(*head)->after = tmp->after;
	tmp->after = *head;
	tmp->before = (*head)->before;
	(*head)->before = tmp;
	if (tmp->is_last)
	{
		tmp->is_last = 0;
		(*head)->is_last = 1;
	}
	*head = tmp;
	return (1);
}

void	sa(t_stack **a)
{
	if (ft_swap(a))
		write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	if (ft_swap(b))
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	if (ft_swap(a) && ft_swap(b))
		write(1, "ss\n", 3);
}
