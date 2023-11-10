/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:56:23 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/10 16:00:40 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_revrotate(t_stack **head)
{
	t_stack	*last;

	if (!head || !(ft_stack_len(*head)) || ft_stack_len(*head) == 1)
		return (0);
	last = ft_last_node(*head);
	last->is_last = 0;
	last->before->is_last = 1;
	*head = last;
	return (1);
}

void	rra(t_stack **a)
{
	if (ft_revrotate(a))
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	if (ft_revrotate(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	if (ft_revrotate(a) && ft_revrotate(b))
		write(1, "rrr\n", 4);
}
