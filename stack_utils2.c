/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:46:04 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/16 12:23:52 by sbelomet         ###   ########.fr       */
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

void	ft_biggest_smaller(t_stack **head, t_stack *current)
{
	t_stack	*tmp;

	tmp = *head;
	current->biggest_smaller = NULL;
	while (tmp)
	{
		if (tmp->value < current->value)
		{
			if (!(current->biggest_smaller)
				|| tmp->value > current->biggest_smaller->value)
				current->biggest_smaller = tmp;
		}
		if (tmp->is_last)
			break ;
		tmp = tmp->after;
	}
	if (!current->biggest_smaller)
		current->biggest_smaller = ft_biggest_node(head);
}

void	ft_reset_cheapest(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (head)
	{
		head->cheapest = 0;
		if (head->is_last)
			break ;
		head = head->after;
	}
}
