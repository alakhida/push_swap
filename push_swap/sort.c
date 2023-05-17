/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:17:55 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/17 06:42:05 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void create_stack(char **numbers, t_data *data)
{
	int idx;
	
	idx = 0;
	data->a_list = malloc(len_2d(numbers));
	data->a_max_size = len_2d(numbers);
	while (idx < data->a_max_size)
	{
		data->a_list[idx] = ft_atoi(numbers[idx]);
		idx++;
	}
}

void sort(char **av)
{
	t_data stack_a;
	t_data stack_b;
	
	int x = 0;
	create_stack(av, &stack_a);
	stack_b.a_list = NULL;
	stack_b.a_max_size = 0;
	while (x < stack_a.a_max_size)
	{
		printf("%d\n", stack_a.a_list[x]);
		x++;
	}
	printf("000000000000000000000000000000000\n");
	push_stack(&stack_a, &stack_b);
	// x = 0;
	// while (x < stack_a.a_max_size)
	// {
	// 	printf("%d\n", stack_a.a_list[x]);
	// 	x++;
	// }
	// x = 0;
	// printf("------------------------\n");
	// while (x < stack_b.a_max_size)
	// {
	// 	printf("%d\n", stack_b.a_list[x]);
	// 	x++;
	// }

}