/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:46:04 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/13 15:04:58 by sbelomet         ###   ########.fr       */
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

t_stack	*ft_biggest_smaller(t_stack **head, int target)
{
	t_stack	*tmp;
	t_stack	*biggest_smaller;

	tmp = *head;
	biggest_smaller = NULL;
	printf("start tmp: %d, TARGET: %d\n", tmp->value, target);
	while (tmp)
	{
		if (tmp->value < target)
		{
			printf("tmp: %d\n", tmp->value);
			if (!biggest_smaller || tmp->value > biggest_smaller->value)
			{
				biggest_smaller = tmp;
				printf("biggist smaller: %d\n", biggest_smaller->value);
			}
		}
		if (tmp->is_last)
			break ;
		tmp = tmp->after;
	}
	if (!biggest_smaller)
		biggest_smaller = ft_biggest_node(head);
	return (biggest_smaller);
}
