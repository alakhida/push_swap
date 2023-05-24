/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:17:55 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/24 16:31:46 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void create_stack(char **numbers, t_data *data)
{
	int idx;
	
	idx = 0;
	data->a_list = malloc(sizeof(int) * len_2d(numbers));
	data->a_max_size = len_2d(numbers);
	while (idx < data->a_max_size)
	{
		data->a_list[idx] = ft_atoi(numbers[idx]);
		idx++;
	}
	if (numbers == NULL)
		free_2d(numbers);
}

void deside_case(t_data *stack_a, t_data *stack_b)
{
	if (stack_a->a_max_size == 2)
		sort_two_num(stack_a);
	else if (stack_a->a_max_size == 3)
		sort_three_numbers(stack_a);
	else if (stack_a->a_max_size == 4)
		four_fifth_case(stack_a, stack_b, 1);
	else if (stack_a->a_max_size == 5)
		four_fifth_case(stack_a, stack_b, 2);
	else if (stack_a->a_max_size <= 100)
	{
		sort_big_num(stack_a, stack_b, 0, 15);
	}
	else if (stack_a->a_max_size > 100)
	{
		sort_big_num(stack_a, stack_b, 0, 35);
	}

}

void sort(char **av)
{
	t_data stack_a;
	t_data stack_b;

	int biggest_num;
	int biggest_num_pos; 
	
	int x = 0;
	create_stack(av, &stack_a);
	if (check_is_sorted(&stack_a))
		return ;
	stack_b.a_list = NULL;
	stack_b.a_max_size = 0;
	deside_case(&stack_a, &stack_b);
	printf("%s", check_is_sorted(&stack_a) == 1 ? "true" : "false");
	free (stack_a.a_list);
	free (stack_b.a_list);
	}
