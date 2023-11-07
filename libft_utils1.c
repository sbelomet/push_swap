/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:12:59 by sbelomet          #+#    #+#             */
/*   Updated: 2023/11/07 15:24:25 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	i = ft_strlen(s1);
	s2 = (char *)malloc(i * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len_s1;
	int		tlen;
	int		i;
	char	*res;

	len_s1 = ft_strlen(s1);
	tlen = len_s1 + ft_strlen(s2);
	res = (char *)malloc(tlen * sizeof(char) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[len_s1 + i] = s2[i];
		i++;
	}
	res[len_s1 + i] = '\0';
	return (res);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*res;
	int		strlen;

	i = 0;
	strlen = ft_strlen(s);
	if (len > strlen)
		len = strlen;
	res = (char *)malloc(len * sizeof(char) + 1);
	if (!res)
		return (NULL);
	if (start < strlen)
	{	
		while (s[i + start] && i < len)
		{
			res[i] = s[i + start];
			i++;
		}
	}
	res[i] = '\0';
	return (res);
}
