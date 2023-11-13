/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:51:40 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/13 15:59:31 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_calculate_cost(t_stack **a, t_stack **b,
			t_stack *current, t_stack *biggest_smaller)
{
	t_stack	*atmp;
	t_stack	*btmp;
	int		cost;

	atmp = *a;
	btmp = *b;
	cost = 0;
	while (atmp != current && btmp != biggest_smaller)
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
	while (btmp != biggest_smaller)
	{
		cost++;
		btmp = btmp->after;
	}
	return (cost + 1);
}

t_stack	*ft_find_cheapest_move(t_stack **a, t_stack **b,
			t_stack *biggest_smaller)
{
	int		cost;
	int		smallest_cost;
	t_stack	*current;
	t_stack	*cheapest;

	smallest_cost = 0;
	current = *a;
	while (current)
	{
		biggest_smaller = ft_biggest_smaller(b, current->value);
		cost = ft_calculate_cost(a, b, current, biggest_smaller);
		if (!(smallest_cost) || cost < smallest_cost)
		{
			smallest_cost = cost;
			cheapest = current;
		}
		if (current->is_last)
			break ;
		current = current->after;
	}
	return (cheapest);
}

void	ft_push_cheapest(t_stack **a, t_stack **b,
			t_stack *atarget, t_stack *btarget)
{
	// todo
}

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
	t_stack	*biggest_smaller;

	while (ft_stack_len(*a) > 3 && ft_stack_len(*b) != 2)
		pb(a, b);
	while (ft_stack_len(*a) > 3)
	{	
		cheapest = ft_find_cheapest_move(a, b, biggest_smaller);
		ft_push_cheapest(a, b, cheapest, biggest_smaller);
	}
	ft_tiny_sort(a);
}
