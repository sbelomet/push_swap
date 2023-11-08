/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:49:16 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/08 16:02:14 by sbelomet         ###   ########.fr       */
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
	t_stack	*tmp;

	i = 0;
	tmp = first_node;
	while (tmp)
	{
		tmp = tmp->after;
		i++;
	}
	return (i);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;

	current = *stack;
	while (current)
	{
		tmp = current->after;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	ft_make_stack(t_stack **a, char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		ft_stack_add_front(a, ft_atoi(av[i]));
		i++;
	}
}

void	ft_stack_add_front(t_stack **stack, int value)
{
	t_stack	*new;

	new = ft_stack_new_node(value);
	if (*stack)
	{
		(*stack)->before = new;
		new->after = *stack;
	}
	*stack = new;
}
