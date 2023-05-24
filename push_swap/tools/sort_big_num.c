/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 04:13:27 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/24 16:29:35 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void normal_sort(t_data *tmp_stack)
{
	int holder;
	int sorted = 0;

	while (!sorted)
	{
		sorted = 1;
		int idx = 0;

		while (idx < tmp_stack->a_max_size - 1)
		{
			if (tmp_stack->a_list[idx] > tmp_stack->a_list[idx + 1])
			{
				holder = tmp_stack->a_list[idx];
				tmp_stack->a_list[idx] = tmp_stack->a_list[idx + 1];
				tmp_stack->a_list[idx + 1] = holder;
				sorted = 0;
			}
			idx++;
		}
	}
}

void init_tmp_stack(t_data *tmp_stack, t_data *stack_a)
{
	int idx;

	idx = 0;
	tmp_stack->a_list = malloc(sizeof(int) * stack_a->a_max_size);
	tmp_stack->a_max_size = stack_a->a_max_size;
	while (idx < tmp_stack->a_max_size)
	{
		tmp_stack->a_list[idx] = stack_a->a_list[idx];
		idx++;
	}
	normal_sort(tmp_stack);
}

int is_after(t_data *tmp_stack, t_data *stack_a, int range_to)
{
	while (range_to < tmp_stack->a_max_size)
	{
		if (stack_a->a_list[0] == tmp_stack->a_list[range_to])
			return (1);
		range_to++;
	}
	return (0);
}

int is_in_range(t_data *tmp_stack, t_data *stack_a, int range_from, int range_to)
{
	while (range_from <= range_to)
	{
		if (stack_a->a_list[0] == tmp_stack->a_list[range_from])
			return (1);
		range_from++;
	}
	return (0);
}

int is_befor_range(t_data *tmp_stack, t_data *stack_a, int range_from)
{
	while (range_from >= 0)
	{
		if (stack_a->a_list[0] == tmp_stack->a_list[range_from])
			return (1);
		range_from--;
	}
	return (0);
}

void exec_moves(t_moves moves, t_data *stack)
{
	while (moves.stack_moves_count > 0)
	{
		if (ft_strncmp(moves.stack_moves_type, "rb", 4) == 0)
		{
			rotate(stack);
			ft_putstr("rb\n");
			moves.stack_moves_count--;
		}
		else
		{
			reverse_rotate(stack);
			ft_putstr("rrb\n");
			moves.stack_moves_count--;
		}
	}
}

t_moves get_moves_needed2(t_data *stack, int pos)
{
	t_moves moves;
	
	if (pos > stack->a_max_size / 2)
	{
		moves.stack_moves_count = stack->a_max_size - pos;
		moves.stack_moves_type = "rrb";
		return moves;
	}
	moves.stack_moves_count = pos;
	moves.stack_moves_type = "rb";
	return (moves);
	
}

void push_to_a(t_data *stack_a, t_data *stack_b)
{
	int num_pos;
	t_moves moves;
	int count;
	while (stack_b->a_max_size > 0)
	{
		num_pos = get_num_position(stack_b, get_big_num(stack_b));
		if (num_pos > (stack_b->a_max_size / 2))
		{
			count = stack_b->a_max_size - num_pos;
			while (count > 0)
			{
				reverse_rotate(stack_b);
				printf("rrb\n");
				count--;
			}
		}else
		{
			count = num_pos;
			while (count > 0)
			{
				rotate(stack_b);
				printf("rb\n");
				count--;
			}
		}
		push_stack(stack_b, stack_a);
		printf("pa\n");
	}
}

void sort_big_num(t_data *stack_a, t_data *stack_b, int range_from, int range_to)
{
	t_data tmp_stack;

	init_tmp_stack(&tmp_stack, stack_a);
	while (stack_a->a_max_size > 0)
	{
		if (is_in_range(&tmp_stack, stack_a, range_from, range_to) == 1)
		{
			push_stack(stack_a, stack_b);
			ft_putstr("pb\n");
			range_to++;
			range_from++;
		}
		else if (is_after(&tmp_stack, stack_a, range_to) == 1)
		{	
			rotate(stack_a);
			ft_putstr("ra\n");
		}
		else if (is_befor_range(&tmp_stack, stack_a, range_from) == 1)
		{
			push_stack(stack_a, stack_b);
			ft_putstr("pb\n");
			rotate(stack_b);
			ft_putstr("rb\n");
			range_from++;
			range_to++;
		}
	}
	push_to_a(stack_a, stack_b);
	free(tmp_stack.a_list);
}