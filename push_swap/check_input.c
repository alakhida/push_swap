
#include "push_swap.h"
#include "./libft/libft.h"

int	check_double(char **arr)
{
	int	i;
	int	j;

	i = 0;

	// printf("%d\n", ft_strncmp(arr[0], arr[1], 5));
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			// printf("%s / %s\n", arr[i], arr[j]);
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int check_int_ragne(char **numbers)
{
	int i;

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
	if (arr[i] == '\0')
		return (0);
	if ((arr[i] == '-' || arr[i] == '+') && isdigit(arr[i + 1]))
		i++;
	if (arr[i] == 32 && arr[i + 1] == 32)
		{
			printf("htewrhh\n");
			exit (1);
		}
	while (arr[i])
	{
		if (!isdigit(arr[i]))
			return (0);
		i++;
	}
	return (1);
}

int check_char(char **numbers)
{
	int i;
	int j;

	i = 0;
	while (numbers[i])
	{
		j = 0;
		while (numbers[i][j])
		{
			if ((numbers[i][j] == '-' || numbers[i][j] == '+') && j != 0)
				return (0);
			else if (numbers[i][j] == '-' || numbers[i][j] == '+')
				j++;
			if (numbers[i][j] < '0' || numbers[i][j] > '9')
				return (0);
			j++;
		}
	i++;
	}
	return (1);
}

int	is_valid_inputs(int ac, char **argv)
{
	int i;
	char *joined_av;
	char **numbers;

	joined_av = get_argv(argv);
	numbers = ft_split(joined_av, ' ');
	i = 0;
	if (!check_int_ragne(numbers))
	{
		
		printf("Number is greater or smaller than int range\n");
		exit (1);
	}
	 if (!check_double(numbers))
	{
		printf("Doublicated numbers\n");
		exit (1);
	}
	if (!check_char(numbers))
	{
		printf("There is a char in argv\n");
		exit (1);
	}
	free(joined_av);
	free_2d(numbers);
	return (1);
}