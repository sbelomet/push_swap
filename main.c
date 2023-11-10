/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:04:32 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/10 16:01:12 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		ft_putnbr_fd(tmp->value, 1);
		write(1, ", ", 2);
		if (tmp->is_last)
			break ;
		tmp = tmp->after;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	av = ft_join_args(av);
	if (!av || ac == 1 || !(is_numerical(av)))
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	ft_make_stack(&a, av);
	if (!is_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a);
		else if (ft_stack_len(a) == 3)
			ft_tiny_sort(&a);
		else
			ft_turc(&a, &b);
	}
	ft_free_stack(&a);
	ft_free_stack(&b);
	ft_free_array(av);
	printf("OK\n");
}
