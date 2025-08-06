/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:25:47 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/24 17:25:47 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	check_double(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_int_range(char **numbers)
{
	int		i;

	i = 0;
	while (numbers[i])
	{
		if (!is_int(numbers[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_input(char *arr)
{
	int	i;

	i = 0;
	if (!arr || arr[i] == '\0')
		return (0);
	if ((arr[i] == '-' || arr[i] == '+') && isdigit(arr[i + 1]))
		i++;
	while (arr[i])
	{
		if (!isdigit(arr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_char(char **numbers)
{
	int		i;
	int		j;

	if (!numbers)
		return (0);
	i = 0;
	while (numbers[i])
	{
		j = 0;
		if (!numbers[i])
			return (0);
		while (numbers[i][j])
		{
			if (numbers[i][j] == '\n')
			{
				j++;
				continue;
			}
			if ((numbers[i][j] == '-' || numbers[i][j] == '+') && j != 0)
				return (0);
			else if ((numbers[i][j] == '-' || numbers[i][j] == '+') && j == 0)
			{
				j++;
				if (!numbers[i][j] || !isdigit(numbers[i][j]))
					return (0);
				continue;
			}
			if (!isdigit(numbers[i][j]))
				return (0);
			j++;
		}
		if (j == 0 || (j == 1 && (numbers[i][0] == '-' || numbers[i][0] == '+')))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_inputs(int ac, char **argv)
{
	char	*joined_av;
	char	**numbers;
	int		result;

	if (!argv)
		return (0);
	joined_av = get_argv(argv);
	if (!joined_av)
		return (0);
	numbers = ft_split(joined_av, ' ');
	if (!numbers)
	{
		free(joined_av);
		return (0);
	}
		result = 1;
	if (!check_double(numbers))
		result = 0;
	else if (!check_char(numbers))
		result = 0;
	else if (!check_int_range(numbers))
		result = 0;
	free_2d(numbers);
	free(joined_av);
	if (!result)
		print_error(1);	
	return (result);
}