/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:05:51 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/08 15:56:44 by sbelomet         ###   ########.fr       */
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
	struct s_stack	*before;
	struct s_stack	*after;
}					t_stack;

t_stack	*ft_stack_new_node(int value);
void	ft_stack_add_front(t_stack **stack, int value);
int		ft_stack_len(t_stack *first_node);
void	ft_make_stack(t_stack **a, char **av);
void	ft_free_stack(t_stack **stack);

int		is_numerical(char **tab);
char	**ft_join_args(char **av);
void	ft_free_array(char **array);
int		check_doubles(char **tab);

int		ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
char	**ft_split(char *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(char *str);
int		ft_strncmp(char *s1, char *s2);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

#endif