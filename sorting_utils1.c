/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:07:52 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/14 14:07:47 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// todo: remake cost calc to include revrot, good luck hihi

int	ft_calculate_cost(t_stack **a, t_stack **b, t_stack *current)
{
	t_stack	*atmp;
	t_stack	*btmp;
	int		cost;

	atmp = *a;
	btmp = *b;
	cost = 0;
	while (atmp != current && !(btmp->biggest_smaller))
	{
		cost++;
		atmp = atmp->after;
		btmp = btmp->after;
	}
	while (atmp != current)
	{
		cost++;
		atmp = atmp->after;
	}
	while (!(btmp->biggest_smaller))
	{
		cost++;
		btmp = btmp->after;
	}
	return (cost + 1);
}

void	ft_find_cheapest_move(t_stack **a, t_stack **b)
{
	int		cost;
	int		smallest_cost;
	t_stack	*current;
	t_stack	*cheapest;

	smallest_cost = 0;
	ft_reset_node_params(a, 'c');
	current = *a;
	while (current)
	{
		ft_biggest_smaller(b, current->value);
		cost = ft_calculate_cost(a, b, current);
		if (!(smallest_cost) || cost < smallest_cost)
		{
			smallest_cost = cost;
			cheapest = current;
		}
		if (current->is_last)
			break ;
		current = current->after;
	}
	cheapest->cheapest = 1;
}

void	ft_push_cheapest(t_stack **first, t_stack **second, char mode)
{
	if (mode == 'a')
	{
		while (!((*first)->cheapest) && !((*second)->biggest_smaller))
			rr(first, second);
		while (!((*first)->cheapest))
			ra(first);
		while (!((*second)->biggest_smaller))
			rb(second);
		pb(first, second);
	}
	else if (mode == 'b')
	{
		while (!((*first)->cheapest) && !((*second)->biggest_smaller))
			rr(first, second);
		while (!((*first)->cheapest))
			rb(first);
		while (!((*second)->biggest_smaller))
			ra(second);
		pa(second, first);
	}
}
