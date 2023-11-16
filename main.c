/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:04:32 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/16 13:13:33 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	av = ft_join_args(av);
	if (!av || ac == 1 || !(is_numerical(av)))
	{
		ft_free_array(av);
		write(1, "Error\n", 6);
		exit(0);
	}
	ft_make_stack(&a, av);
	ft_free_array(av);
	if (!is_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a);
		else if (ft_stack_len(a) == 3)
			ft_tiny_sort(&a);
		else
			ft_turkish_sort(&a, &b);
	}
	ft_free_stack(&b);
	ft_free_stack(&a);
}
