/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:04:32 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/09 11:57:11 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack **stack) /*for testing, disable later*/
{
	t_stack	*tmp;

	tmp = *stack;
	//printf("is_last: %d, who: %d\n", tmp->is_last, tmp->value);
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
	printf("yo\n");
	ft_make_stack(&a, av);
	printf("ya\n");
	ft_print_stack(&a);
	printf("did print of a\n");
	ft_print_stack(&b);
	printf("did print of b\n");
	sa(&a);
	printf("did sa\n");
	pa(&a, &b);
	printf("did pa\n");
	ft_print_stack(&a);
	printf("did print of a\n");
	ft_print_stack(&b);
	printf("did print of b\n");
	pb(&a, &b);
	printf("did pb\n");
	ft_print_stack(&a);
	printf("did print of a\n");
	ft_print_stack(&b);
	printf("did print of b\n");
	//pb(&a, &b);
	//ss(&a, &b);
	/*if (!is_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a);
		else if (ft_stack_len(a) == 3)
			ft_tiny_sort(&a);
		else
			ft_push_swap(&a, &b);
	}*/
	ft_print_stack(&a);
	ft_print_stack(&b);
	ft_free_stack(&a);
	ft_free_stack(&b);
	ft_free_array(av);
	printf("OK\n");
}
