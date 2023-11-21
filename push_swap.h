/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:05:51 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/21 11:16:30 by sbelomet         ###   ########.fr       */
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
	int				cheapest;
	struct s_stack	*biggest_smaller;
	struct s_stack	*before;
	struct s_stack	*after;
}					t_stack;

/*Utils*/
int				is_numerical(char **tab);
char			**ft_join_args(char **av);
void			ft_free_array(char **array);
int				check_doubles(char **tab);
int				is_sorted(t_stack *a);
int				check_max(char **tab);

/*Stack Utils*/
t_stack			*ft_stack_new_node(int value);
void			ft_stack_add_front(t_stack **stack, t_stack *new);
void			ft_stack_add_back(t_stack **stack, t_stack *new);
int				ft_stack_len(t_stack *first_node);
void			ft_make_stack(t_stack **a, char **av);
void			ft_free_stack(t_stack **stack);
t_stack			*ft_last_node(t_stack *node);
t_stack			*ft_biggest_node(t_stack **head);
t_stack			*ft_smallest_node(t_stack **head);
void			ft_biggest_smaller(t_stack **head, t_stack *current);
void			ft_reset_cheapest(t_stack **stack);

/*Libft Utils*/
int				ft_strlen(char *s);
char			*ft_strdup(char *s1);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_substr(char *s, int start, int len);
char			**ft_split(char *s, char c);
long long int	ft_atoi(char *str);
int				ft_strcmp(char *s1, char *s2);

/*Swap Commands*/
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);

/*Push Commands*/
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);

/*Rotate Commands*/
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);

/*Reverse Rotate Commands*/
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);

/*Cost Calc Commands*/
int				ft_calculate_cost(t_stack **a, t_stack **b, t_stack *current);
int				ft_calcrrarrb(t_stack **a, t_stack **b,
					t_stack *atarget, t_stack *btarget);
int				ft_calcrrarb(t_stack **a, t_stack **b,
					t_stack *atarget, t_stack *btarget);
int				ft_calcrarrb(t_stack **a, t_stack **b,
					t_stack *atarget, t_stack *btarget);
int				ft_calcrarb(t_stack **a, t_stack **b,
					t_stack *atarget, t_stack *btarget);

/*Push Cheap Commands*/
void			ft_rrarrb(t_stack **first, t_stack **second,
					t_stack *cheapest, char mode);
void			ft_rrarb(t_stack **first, t_stack **second,
					t_stack *cheapest, char mode);
void			ft_rarrb(t_stack **first, t_stack **second,
					t_stack *cheapest, char mode);
void			ft_rarb(t_stack **first, t_stack **second,
					t_stack *cheapest, char mode);

/*Sort Utils*/
t_stack			*ft_find_cheapest_move(t_stack **a, t_stack **b);
int				ft_find_node_index(t_stack **head, t_stack *to_find);
void			ft_push_cheapest(t_stack **a, t_stack **b,
					t_stack *cheapest, char mode);
t_stack			*ft_find_node_address(t_stack **head, char mode);

/*Sort Commands*/
void			ft_tiny_sort(t_stack **head);
void			ft_turkish_sort(t_stack **a, t_stack **b);

#endif