/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:28:32 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/10 15:11:36 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_push(t_stack **donor, t_stack **receiver)
{
	t_stack	*new_head;

	if (!donor || !(ft_stack_len(*donor)))
		return (0);
	if (ft_stack_len(*donor) == 1)
	{
		ft_stack_add_front(receiver, *donor);
		*donor = NULL;
		return (1);
	}
	new_head = (*donor)->after;
	new_head->before = (*donor)->before;
	new_head->before->after = new_head;
	ft_stack_add_front(receiver, *donor);
	*donor = new_head;
	return (1);
}

void	pa(t_stack **a, t_stack **b)
{
	if (ft_push(b, a))
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	if (ft_push(a, b))
		write(1, "pb\n", 3);
}
