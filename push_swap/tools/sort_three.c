/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 01:02:24 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/24 16:18:35 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

static int	second_case(t_data *stack_a)
{
	if ((stack_a->a_list[0] > stack_a->a_list[1])
		&& (stack_a->a_list[1] > stack_a->a_list[2])
		&& ((stack_a->a_list[2] < stack_a->a_list[1])
			&& (stack_a->a_list[2] < stack_a->a_list[0])))
	{
		swap(stack_a);
		ft_putstr("sa\n");
		reverse_rotate(stack_a);
		ft_putstr("rra\n");
		return (1);
	}
	return (0);
}

static int	third_case(t_data *stack_a)
{
	if ((stack_a->a_list[0] > stack_a->a_list[1])
		&& (stack_a->a_list[1] < stack_a->a_list[2])
		&& ((stack_a->a_list[2] < stack_a->a_list[0])
			&& (stack_a->a_list[2] > stack_a->a_list[1])))
	{
		rotate(stack_a);
		ft_putstr("ra\n");
		return (1);
	}
		free(stack_a->a_list);
	return (0);
}

static int	fourth_case(t_data *stack_a)
{
	if ((stack_a->a_list[0] < stack_a->a_list[1])
		&& (stack_a->a_list[1] > stack_a->a_list[2])
		&& (stack_a->a_list[2] < stack_a->a_list[1])
		&& (stack_a->a_list[2] > stack_a->a_list[0]))
	{
		swap(stack_a);
		ft_putstr("sa\n");
		rotate(stack_a);
		ft_putstr("ra\n");
		return (1);
	}
	return (0);
}

static int	fifth_case(t_data *stack_a)
{
	if ((stack_a->a_list[0] < stack_a->a_list[1])
		&& (stack_a->a_list[0] > stack_a->a_list[2])
		&& (stack_a->a_list[1] > stack_a->a_list[0])
		&& (stack_a->a_list[1] > stack_a->a_list[2]))
	{
		reverse_rotate(stack_a);
		ft_putstr("rra\n");
		return (1);
	}
	return (0);
}

int	sort_three_numbers(t_data *stack_a)
{
	
	if ((stack_a->a_list[0] > stack_a->a_list[1])
		&& (stack_a->a_list[1] < stack_a->a_list[2])
		&& ((stack_a->a_list[2] > stack_a->a_list[1])
			&& (stack_a->a_list[2] > stack_a->a_list[0])))
	{
		
		swap(stack_a);
		ft_putstr("sa\n");
		return (1);
	}
	else if (second_case(stack_a))
		return (1);
	else if (third_case(stack_a))
		return (1);
	else if (fourth_case(stack_a))
		return (1);
	else if (fifth_case(stack_a))
		return (1);
	return (0);
}

int sort_two_num(t_data *stack_a)
{
	if ((stack_a->a_list[0] > stack_a->a_list[1]))
	{
		swap(stack_a);
		ft_putstr("sa\n");
		return (1);
	}
	return (0);
}
