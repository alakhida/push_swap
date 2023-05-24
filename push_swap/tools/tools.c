/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 01:23:02 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/24 01:31:40 by alakhida         ###   ########.fr       */
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

int get_min_num(t_data *stack)
{
	int idx;
	int holder;

	holder = stack->a_list[0];

	idx = 0;
	while (idx < stack->a_max_size)
	{
		if (stack->a_list[idx] < holder)
			holder = stack->a_list[idx];
		idx++;
	}
	return (holder);
}

int get_big_num(t_data *stack)
{
	int idx;
	int holder;

	holder = stack->a_list[0];
	idx = 0;
	while (idx < stack->a_max_size)
	{
		if (stack->a_list[idx] > holder)
			holder = stack->a_list[idx];
		idx++;
	}
	return (holder);
}

int get_num_position(t_data *stack, int num)
{
	int idx;

	idx = 0;
	while (idx < stack->a_max_size)
	{
		if (num == stack->a_list[idx])
			return (idx);
		idx++;
	}
	//return -1 if didn't work
	return (0);
}

t_moves get_moves_needed(t_data *stack, int pos)
{
	t_moves moves;
	
	if (pos > stack->a_max_size / 2)
	{
		moves.stack_moves_count = stack->a_max_size - pos;
		moves.stack_moves_type = "rra";
		return moves;
	}
	moves.stack_moves_count = pos;
	moves.stack_moves_type = "ra";
	return (moves);
	
}

int check_is_sorted(t_data *stack)
{
	int	idx;

	idx = 0;
	while (idx < stack->a_max_size)
	{
		if (idx + 1 == stack->a_max_size)
			return (1);
		if (stack->a_list[idx] > stack->a_list[idx + 1])
			return (0);
		idx++;
	}
	free (stack->a_list);
	return (1);
}