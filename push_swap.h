/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:05:51 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/14 12:12:28 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				is_last;
	int				biggest_smaller;
	int				cheapest;
	struct s_stack	*before;
	struct s_stack	*after;
}					t_stack;

void	ft_print_stack(t_stack **stack);

/*Utils*/
int		is_numerical(char **tab);
char	**ft_join_args(char **av);
void	ft_free_array(char **array);
int		check_doubles(char **tab);
int		is_sorted(t_stack *a);

/*Stack Utils*/
t_stack	*ft_stack_new_node(int value);
void	ft_stack_add_front(t_stack **stack, t_stack *new);
void	ft_stack_add_back(t_stack **stack, t_stack *new);
int		ft_stack_len(t_stack *first_node);
void	ft_make_stack(t_stack **a, char **av);
void	ft_free_stack(t_stack **stack);
t_stack	*ft_last_node(t_stack *node);
t_stack	*ft_biggest_node(t_stack **head);
void	ft_biggest_smaller(t_stack **head, int target);
void	ft_reset_node_params(t_stack **stack, char param);

/*Libft Utils*/
int		ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
char	**ft_split(char *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);

/*Swap Commands*/
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

/*Push Commands*/
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

/*Rotate Commands*/
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

/*Reverse Rotate Commands*/
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/*Sort Utils*/
int		ft_calculate_cost(t_stack **a, t_stack **b, t_stack *current);
void	ft_find_cheapest_move(t_stack **a, t_stack **b);
void	ft_push_cheapest(t_stack **a, t_stack **b, char mode);

/*Sort Commands*/
void	ft_tiny_sort(t_stack **head);
void	ft_turkish_sort(t_stack **a, t_stack **b);

#endif