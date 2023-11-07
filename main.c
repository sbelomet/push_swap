/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:04:32 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/07 15:42:41 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	av = ft_join_args(av);
	ft_make_stack(av);
	/*if (!is_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a);
		else if (ft_stack_len(a) == 3)
			ft_tiny_sort(&a);
		else
			ft_push_swap(&a, &b);
	}*/
	ft_printfree(&a);
	/*i = 1;
	while (av[i])
	{
		if (!is_numerical(av[i]))
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		i++;
	}*/
	ft_free_array(av);
}
