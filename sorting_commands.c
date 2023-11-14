/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:51:40 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/14 14:05:50 by sbelomet         ###   ########.fr       */
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
	while (ft_stack_len(*a) > 3 && ft_stack_len(*b) != 2)
		pb(a, b);
	while (ft_stack_len(*a) > 3)
	{	
		ft_find_cheapest_move(a, b);
		ft_push_cheapest(a, b, 'a');
	}
	ft_tiny_sort(a);
	while (ft_stack_len(*b))
	{
		ft_print_stack(a);
		ft_print_stack(b);
		ft_find_cheapest_move(b, a);
		ft_print_stack(b);
		ft_push_cheapest(b, a, 'b');
	}
	ft_print_stack(a);
	ft_free_stack(a);
	ft_free_stack(b);
}
