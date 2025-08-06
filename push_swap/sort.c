/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:17:55 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/25 04:56:42 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	create_stack(char **numbers, t_data *data)
{
	int		idx;
	char	*joined_av;
	char	**splited_av;

	joined_av = get_argv(numbers);
	splited_av = ft_split(joined_av, ' ');
	idx = 0;
	data->a_list = malloc(sizeof(int) * len_2d(splited_av));
	data->a_max_size = len_2d(splited_av);
	while (idx < data->a_max_size)
	{
		data->a_list[idx] = ft_atoi(splited_av[idx]);
		idx++;
	}
	free_2d(splited_av);
}

void	deside_case(t_data *stack_a, t_data *stack_b)
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
		sort_big_num(stack_a, stack_b, 0, 17);
	}
	else if (stack_a->a_max_size > 100)
	{
		sort_big_num(stack_a, stack_b, 0, 40);
	}
}

void	sort(int count, char **av)
{
	t_data	stack_a;
	t_data	stack_b;
	int		biggest_num;
	int		biggest_num_pos;

	create_stack(av, &stack_a);
	stack_b.a_list = NULL;
	stack_b.a_max_size = 0;
	if (check_is_sorted(&stack_a))
		return ;
	deside_case(&stack_a, &stack_b);
	free (stack_a.a_list);
	free (stack_b.a_list);
}
