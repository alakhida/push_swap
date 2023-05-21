/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:17:55 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/21 07:26:42 by alakhida         ###   ########.fr       */
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
}

void deside_case(t_data *stack_a, t_data *stack_b)
{
	if (stack_a->a_max_size == 3)
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
		sort_big_num(stack_a, stack_b, 0, 31);
	}
}
void printStacksVertically(t_data stack_a, t_data stack_b)
{
    int max_size = (stack_a.a_max_size > stack_b.a_max_size) ? stack_a.a_max_size : stack_b.a_max_size;
    int i;

    printf("Stack A\t\tStack B\n");
    printf("-----------------------\n");

    for (i = 0; i < max_size; i++) {
        if (i < stack_a.a_max_size) {
            printf("%d\t\t", stack_a.a_list[i]);
        } else {
            printf("\t\t");
        }

        if (i < stack_b.a_max_size) {
            printf("%d", stack_b.a_list[i]);
        }

        printf("\n");
    }

    printf("-----------------------\n");
}
void sort(char **av)
{
	t_data stack_a;
	t_data stack_b;

	int biggest_num;
	int biggest_num_pos; 
	
	int x = 0;
	create_stack(av, &stack_a);
	stack_b.a_list = NULL;
	stack_b.a_max_size = 0;

	
	deside_case(&stack_a, &stack_b);

}
