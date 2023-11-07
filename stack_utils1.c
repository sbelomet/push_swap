/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:49:16 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/07 15:26:22 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new_node(int value)
{
	t_stack	*res;

	res = (t_stack *)malloc(sizeof(t_stack));
	if (!res)
		return (NULL);
	res->value = value;
	res->before = NULL;
	res->after = NULL;
	return (res);
}

int	ft_stack_len(t_stack *first_node)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = first_node;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_printfree(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		ft_putnbr_fd(tmp->value, 1);
		tmp = tmp->after;
	}
}

// void	ft_stack_add_front(t_stack **stack, t_stack *new)
// {
// 	if (*stack)
// 	{
// 		*stack->before = new;
// 		new->after = *stack;
// 	}
// 	*stack = new;
// }