/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheap_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:19:39 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/16 12:25:01 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrarrb(t_stack **first, t_stack **second,
			t_stack *cheapest, char mode)
{
	if (mode == 'a')
	{
		while (*first != cheapest && *second != cheapest->biggest_smaller)
			rrr(first, second);
		while (*first != cheapest)
			rra(first);
		while (*second != cheapest->biggest_smaller)
			rrb(second);
		pb(first, second);
	}
	else if (mode == 'b')
	{
		while (*first != cheapest
			&& ft_last_node(*second) != cheapest->biggest_smaller)
			rrr(first, second);
		while (*first != cheapest)
			rrb(first);
		while (ft_last_node(*second) != cheapest->biggest_smaller)
			rra(second);
		pa(second, first);
	}
}

void	ft_rrarb(t_stack **first, t_stack **second,
			t_stack *cheapest, char mode)
{
	if (mode == 'a')
	{
		while (*first != cheapest)
			rra(first);
		while (*second != cheapest->biggest_smaller)
			rb(second);
		pb(first, second);
	}
	else if (mode == 'b')
	{
		while (*first != cheapest)
			rb(first);
		while (ft_last_node(*second) != cheapest->biggest_smaller)
			rra(second);
		pa(second, first);
	}
}

void	ft_rarrb(t_stack **first, t_stack **second,
			t_stack *cheapest, char mode)
{
	if (mode == 'a')
	{
		while (*first != cheapest)
			ra(first);
		while (*second != cheapest->biggest_smaller)
			rrb(second);
		pb(first, second);
	}
	else if (mode == 'b')
	{
		while (*first != cheapest)
			rrb(first);
		while (ft_last_node(*second) != cheapest->biggest_smaller)
			ra(second);
		pa(second, first);
	}
}

void	ft_rarb(t_stack **first, t_stack **second,
			t_stack *cheapest, char mode)
{
	if (mode == 'a')
	{
		while (*first != cheapest && *second != cheapest->biggest_smaller)
			rr(first, second);
		while (*first != cheapest)
			ra(first);
		while (*second != cheapest->biggest_smaller)
			rb(second);
		pb(first, second);
	}
	else if (mode == 'b')
	{
		while (*first != cheapest
			&& ft_last_node(*second) != cheapest->biggest_smaller)
			rr(first, second);
		while (*first != cheapest)
			rb(first);
		while (ft_last_node(*second) != cheapest->biggest_smaller)
			ra(second);
		pa(second, first);
	}
}
