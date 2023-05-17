/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 01:23:02 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/17 06:36:39 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

char *get_argv(char **argv)
{
	char *av_joined;
	int i;

	i = 0;
	av_joined = NULL;
	while (argv[i])
	{
		av_joined = ft_strjoin(av_joined, argv[i]);
		av_joined = ft_strjoin(av_joined, " ");
		i++;
	}
	return (av_joined);
}

int	is_int(const char *str)
{
	int	s;
	long int	r;
	int	i;
	long int holder;

	r = 0;
	s = 1;
	i = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' '
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			s = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r *= 10;
		r += str[i++] - '0';
		holder = r * s;
		if (holder > INT_MAX || holder < INT_MIN)
			return (0);
	}
	return (1);
}