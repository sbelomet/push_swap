/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:51:40 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/21 11:54:53 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tiny_sort(t_stack **head)
{
	t_stack	*biggest;

	biggest = ft_biggest_node(head);
	if (biggest->is_last)
	{
		if ((*head)->value > (*head)->after->value)
			sa(head);
	}
	else if (biggest->before->is_last)
	{
		ra(head);
		if ((*head)->value > (*head)->after->value)
			sa(head);
	}
	else
	{
		if ((*head)->value < (*head)->before->value)
		{
			sa(head);
			ra(head);
		}
		else
			rra(head);
	}
}

void	ft_turkish_sort(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = NULL;
	while (ft_stack_len(*a) > 3 && ft_stack_len(*b) != 2 && !is_sorted(*a))
		pb(a, b);
	while (ft_stack_len(*a) > 3 && !is_sorted(*a))
	{	
		cheapest = ft_find_cheapest_move(a, b);
		ft_push_cheapest(a, b, cheapest, 'a');
	}
	ft_tiny_sort(a);
	while (ft_stack_len(*b))
	{
		cheapest = ft_find_cheapest_move(b, a);
		ft_push_cheapest(b, a, cheapest, 'b');
	}
	while (!(ft_biggest_node(a)->is_last))
	{
		if (ft_find_node_index(a, ft_biggest_node(a)) > ft_stack_len(*a) / 2)
			rra(a);
		else
			ra(a);
	}
}
