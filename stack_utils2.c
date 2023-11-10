/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:46:04 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/10 14:57:56 by sbelomet         ###   ########.fr       */
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
