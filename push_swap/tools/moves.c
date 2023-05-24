/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:17:42 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/24 16:22:24 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"


void swap(t_data *stack)
{
	int holder;

	if (stack->a_max_size < 2)
		return ;
	holder = stack->a_list[0];
	stack->a_list[0] = stack->a_list[1];
	stack->a_list[1] = holder;
}

void rotate(t_data *stack)
{
	int holder;
	int idx;

	if (stack->a_max_size == 0)
		return ;
	holder = stack->a_list[0];
	idx = 1;
	while (idx < stack->a_max_size)
	{
		stack->a_list[idx - 1] = stack->a_list[idx];
		idx++;
	}
	stack->a_list[stack->a_max_size - 1] = holder;
}

void reverse_rotate(t_data *stack)
{
	int holder;
	int idx;

	if (stack->a_max_size == 0)
		return;
	holder = stack->a_list[stack->a_max_size - 1];
	idx = stack->a_max_size - 2;
	while (idx >= 0)
	{
		stack->a_list[idx + 1] = stack->a_list[idx];
		idx--;
	}
	stack->a_list[0] = holder;
}

void push_stack_comp(t_data *stack_from)
{
	t_data tmp_stack;
	int idx;
	int idx2;

	idx = 1;
	idx2 = 0;
	tmp_stack.a_list = malloc(sizeof(int) * (stack_from->a_max_size) - 1);
	tmp_stack.a_max_size = stack_from->a_max_size - 1;
	while (idx2 < tmp_stack.a_max_size)
		tmp_stack.a_list[idx2++] = stack_from->a_list[idx++];
	free(stack_from->a_list);
	stack_from->a_list = tmp_stack.a_list;
	stack_from->a_max_size = tmp_stack.a_max_size;
}

void push_stack(t_data *stack_from, t_data *stack_to)
{
	t_data tmp_stack;
	int idx;
	
	idx = 1;
	if (stack_from->a_max_size == 0)
		return ;
	tmp_stack.a_list = malloc(sizeof(int) * (stack_to->a_max_size + 1));
	if (!tmp_stack.a_list)
		exit(1)	;
	tmp_stack.a_max_size = stack_to->a_max_size + 1;
	tmp_stack.a_list[0] = stack_from->a_list[0];
	while (idx < tmp_stack.a_max_size)
	{
		tmp_stack.a_list[idx] = stack_to->a_list[idx - 1];
		idx++;
	}
	if (stack_to->a_list)
		free(stack_to->a_list);
	stack_to->a_list = tmp_stack.a_list;
	stack_to->a_max_size = tmp_stack.a_max_size;
	push_stack_comp(stack_from);
}
