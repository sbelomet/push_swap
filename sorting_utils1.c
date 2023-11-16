/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:07:52 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/16 12:07:17 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_node_address(t_stack **head, char mode)
{
	t_stack	*res;

	res = *head;
	if (mode == 'b')
	{
		while (res)
		{
			if (res->biggest_smaller)
				return (res);
			res = res->after;
		}
	}
	return (NULL);
}

int	ft_find_node_index(t_stack **head, t_stack *to_find)
{
	t_stack	*tmp;
	int		i;

	tmp = *head;
	i = 0;
	while (tmp != to_find)
	{
		i++;
		tmp = tmp->after;
	}
	return (i);
}

t_stack	*ft_find_cheapest_move(t_stack **a, t_stack **b)
{
	int		cost;
	int		smallest_cost;
	t_stack	*current;
	t_stack	*cheapest;

	smallest_cost = 0;
	ft_reset_cheapest(a);
	current = *a;
	while (current)
	{
		ft_biggest_smaller(b, current);
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
	return (cheapest);
}

void	ft_push_cheapest(t_stack **a, t_stack **b, t_stack *cheapest, char mode)
{
	int		atarget;
	int		btarget;
	int		alen;
	int		blen;

	alen = ft_stack_len(*a);
	blen = ft_stack_len(*b);
	atarget = ft_find_node_index(a, cheapest);
	btarget = ft_find_node_index(b, cheapest->biggest_smaller);
	if (mode == 'b')
	{
		atarget = ft_find_node_index(b, cheapest->biggest_smaller);
		btarget = ft_find_node_index(a, cheapest);
	}
	if (atarget > alen / 2 && btarget > blen / 2)
		ft_rrarrb(a, b, cheapest, mode);
	else if (atarget > alen / 2)
		ft_rrarb(a, b, cheapest, mode);
	else if (btarget > blen / 2)
		ft_rarrb(a, b, cheapest, mode);
	else
		ft_rarb(a, b, cheapest, mode);
}
