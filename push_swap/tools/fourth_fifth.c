/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourth_fifth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 01:25:11 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/21 06:33:59 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void execute_moves(t_moves moves, t_data *stack)
{
	while (moves.stack_moves_count > 0)
	{
		if ((ft_strncmp(moves.stack_moves_type, "ra", 4) == 0))
		{
			rotate(stack);
			ft_putstr("ra\n");
			moves.stack_moves_count--;
		}
		else
		{
			reverse_rotate(stack);
			ft_putstr("rra\n");
			moves.stack_moves_count--;
		}
	}
}

int four_fifth_case(t_data *stack_a, t_data *stack_b, int count)
{
	int smaller_num;
	int smaller_num_pos;
	int holder;
	t_moves moves;
	
	holder = count;
	
	while (count > 0)
	{
		smaller_num = get_min_num(stack_a);
		smaller_num_pos = get_num_position(stack_a ,smaller_num);
		moves = get_moves_needed(stack_a, smaller_num_pos, "rra", "ra");
		execute_moves(moves, stack_a);
		push_stack(stack_a, stack_b);
		ft_putstr("pb\n");
		count--;
	}
	sort_three_numbers(stack_a);
	push_stack(stack_b, stack_a);
	ft_putstr("pa\n");
	if (holder == 2)
	{
		push_stack(stack_b, stack_a);
		ft_putstr("pa\n");
	}
	return(0);
}
