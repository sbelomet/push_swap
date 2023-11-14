/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:46:04 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/14 11:32:14 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_last_node(t_stack *node)
{
	t_stack	*last;

	last = node;
	if (!last)
		return (NULL);
	while (!(last->is_last))
		last = last->after;
	return (last);
}

int	ft_stack_len(t_stack *first_node)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = first_node;
	while (tmp)
	{
		i++;
		if (tmp->is_last)
			break ;
		tmp = tmp->after;
	}
	return (i);
}

t_stack	*ft_biggest_node(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*biggest;
	int		i;
	int		len;

	tmp = *head;
	biggest = *head;
	i = 0;
	len = ft_stack_len(*head);
	while (i < len)
	{
		if (tmp->value > tmp->after->value && tmp->value >= biggest->value)
			biggest = tmp;
		tmp = tmp->after;
		i++;
	}
	return (biggest);
}

void	ft_biggest_smaller(t_stack **head, int target)
{
	t_stack	*tmp;
	t_stack	*bs_node;

	ft_reset_node_params(head, 'b');
	tmp = *head;
	bs_node = NULL;
	while (tmp)
	{
		if (tmp->value < target)
		{
			if (!bs_node || tmp->value > bs_node->value)
			{
				bs_node = tmp;
			}
		}
		if (tmp->is_last)
			break ;
		tmp = tmp->after;
	}
	if (!bs_node)
		bs_node = ft_biggest_node(head);
	bs_node->biggest_smaller = 1;
}

void	ft_reset_node_params(t_stack **stack, char param)
{
	t_stack	*head;

	head = *stack;
	if (param == 'b')
	{
		while (head)
		{
			head->biggest_smaller = 0;
			if (head->is_last)
				break ;
			head = head->after;
		}
	}
	else if (param == 'c')
	{
		while (head)
		{
			head->cheapest = 0;
			if (head->is_last)
				break ;
			head = head->after;
		}
	}
}
