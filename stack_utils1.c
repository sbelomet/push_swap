/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:49:16 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/14 10:14:59 by sbelomet         ###   ########.fr       */
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
	res->is_last = 0;
	res->biggest_smaller = 0;
	res->cheapest = 0;
	return (res);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;

	if (stack)
	{
		current = *stack;
		while (current)
		{
			tmp = current->after;
			free(current);
			if (current->is_last)
				break ;
			current = tmp;
		}
		*stack = NULL;
	}
}

void	ft_make_stack(t_stack **a, char **av)
{
	int		i;
	t_stack	*new;

	i = 0;
	while (av[i])
	{
		new = ft_stack_new_node(ft_atoi(av[i]));
		ft_stack_add_back(a, new);
		i++;
	}
}

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack)
	{
		last = ft_last_node(*stack);
		(*stack)->before = new;
		new->after = *stack;
		last->after = new;
		new->before = last;
		last->is_last = 0;
		new->is_last = 1;
	}
	else
	{
		*stack = new;
		(*stack)->before = *stack;
		(*stack)->after = *stack;
		(*stack)->is_last = 1;
	}
}

void	ft_stack_add_front(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack)
	{
		last = ft_last_node(*stack);
		(*stack)->before = new;
		new->after = *stack;
		last->after = new;
		new->before = last;
		new->is_last = 0;
		*stack = new;
	}
	else
	{
		*stack = new;
		(*stack)->before = *stack;
		(*stack)->after = *stack;
		(*stack)->is_last = 1;
	}
}
