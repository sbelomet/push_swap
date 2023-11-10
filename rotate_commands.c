/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:20:57 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/10 12:00:13 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rotate(t_stack **head)
{
	t_stack	*last;

	if (!head || !(ft_stack_len(*head)) || ft_stack_len(*head) == 1)
		return (0);
	last = ft_last_node(*head);
	last->is_last = 0;
	(*head)->is_last = 1;
	*head = (*head)->after;
	return (1);
}

void	ra(t_stack **a)
{
	if (ft_rotate(a))
		write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	if (ft_rotate(b))
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	if (ft_rotate(a) && ft_rotate(b))
		write(1, "rr\n", 3);
}
