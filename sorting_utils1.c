/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:07:52 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/15 14:37:57 by sbelomet         ###   ########.fr       */
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
				return(res);
			res = res->after;
		}
	}
	return (NULL);
}

int	ft_find_node_index(t_stack **head, char mode)
{
	t_stack	*tmp;
	int		i;

	tmp = *head;
	i = 0;
	if (mode == 'b')
	{
		while (!(tmp->biggest_smaller))
		{
			i++;
			tmp = tmp->after;
		}
	}
	else if (mode == 'c')
	{
		while (!(tmp->cheapest))
		{
			i++;
			tmp = tmp->after;
		}
	}
	return (i);
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
		printf("current: %d, cost: %d\n", current->value, cost);
		if (!(smallest_cost) || cost < smallest_cost)
		{
			smallest_cost = cost;
			cheapest = current;
		}
		if (current->is_last)
			break ;
		current = current->after;
	}
	ft_print_stack(b);
	cheapest->cheapest = 1;
}

void	ft_push_cheapest(t_stack **a, t_stack **b, char mode)
{
	int		atarget;
	int		btarget;
	int		alen;
	int		blen;

	alen = ft_stack_len(*a);
	blen = ft_stack_len(*b);
	atarget = ft_find_node_index(a, 'c');
	btarget = ft_find_node_index(b, 'b');
	if (mode == 'b')
	{
		atarget = ft_find_node_index(a, 'b');
		btarget = ft_find_node_index(b, 'c');
	}
	if (atarget > alen / 2 && btarget > blen / 2)
		ft_rrarrb(a, b, mode);
	else if (atarget > alen / 2)
		ft_rrarb(a, b, mode);
	else if (btarget > blen / 2)
		ft_rarrb(a, b, mode);
	else
		ft_rarb(a, b, mode);
}
