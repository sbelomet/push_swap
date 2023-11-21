/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:18:32 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/21 12:24:08 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_calcrrarrb(t_stack **a, t_stack **b,
		t_stack *atarget, t_stack *btarget)
{
	t_stack	*atmp;
	t_stack	*btmp;
	int		cost;

	atmp = ft_last_node(*a);
	btmp = ft_last_node(*b);
	cost = 2;
	while (atmp != atarget && btmp != btarget)
	{
		cost++;
		atmp = atmp->before;
		btmp = btmp->before;
	}
	while (atmp != atarget)
	{
		cost++;
		atmp = atmp->before;
	}
	while (btmp != btarget)
	{
		cost++;
		btmp = btmp->before;
	}
	return (cost);
}

int	ft_calcrrarb(t_stack **a, t_stack **b,
		t_stack *atarget, t_stack *btarget)
{
	t_stack	*atmp;
	t_stack	*btmp;
	int		cost;

	atmp = ft_last_node(*a);
	btmp = *b;
	cost = 1;
	while (atmp != atarget && btmp != btarget)
	{
		cost++;
		atmp = atmp->before;
		btmp = btmp->after;
	}
	while (atmp != atarget)
	{
		cost++;
		atmp = atmp->before;
	}
	while (btmp != btarget)
	{
		cost++;
		btmp = btmp->after;
	}
	return (cost);
}

int	ft_calcrarrb(t_stack **a, t_stack **b,
		t_stack *atarget, t_stack *btarget)
{
	t_stack	*atmp;
	t_stack	*btmp;
	int		cost;

	atmp = *a;
	btmp = ft_last_node(*b);
	cost = 1;
	while (atmp != atarget && btmp != btarget)
	{
		cost++;
		atmp = atmp->after;
		btmp = btmp->before;
	}
	while (atmp != atarget)
	{
		cost++;
		atmp = atmp->after;
	}
	while (btmp != btarget)
	{
		cost++;
		btmp = btmp->before;
	}
	return (cost);
}

int	ft_calcrarb(t_stack **a, t_stack **b,
		t_stack *atarget, t_stack *btarget)
{
	t_stack	*atmp;
	t_stack	*btmp;
	int		cost;

	atmp = *a;
	btmp = *b;
	cost = 0;
	while (atmp != atarget && btmp != btarget)
	{
		cost++;
		atmp = atmp->after;
		btmp = btmp->after;
	}
	while (atmp != atarget)
	{
		cost++;
		atmp = atmp->after;
	}
	while (btmp != btarget)
	{
		cost++;
		btmp = btmp->after;
	}
	return (cost);
}

int	ft_calculate_cost(t_stack **a, t_stack **b, t_stack *current)
{
	int		atarget;
	int		btarget;
	int		alen;
	int		blen;
	t_stack	*atmp;

	alen = ft_stack_len(*a);
	blen = ft_stack_len(*b);
	atarget = ft_find_node_index(a, current);
	btarget = 0;
	atmp = *a;
	while (atmp != current)
	{
		atarget++;
		atmp = atmp->after;
	}
	if (atarget < alen - atarget && btarget < blen - btarget)
		return (ft_calcrarb(a, b, current, current->biggest_smaller) + 1);
	else if (atarget < alen - atarget)
		return (ft_calcrarrb(a, b, current, current->biggest_smaller) + 1);
	else if (btarget < blen - btarget)
		return (ft_calcrrarb(a, b, current, current->biggest_smaller) + 1);
	return (ft_calcrrarrb(a, b, current, current->biggest_smaller) + 1);
}
