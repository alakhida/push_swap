/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:02:05 by alakhida          #+#    #+#             */
/*   Updated: 2022/11/03 22:48:39 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//this function convert a string representation of an integer to its corresponding integer value.
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	index;

	result = 0;
	sign = 1;
	index = 0;
	//skip whitespaces
	while (str[index] && (str[index] == '\f' || str[index] == '\t' || str[index] == ' '
			|| str[index] == '\n' || str[index] == '\r' || str[index] == '\v'))
		index++;
	//handling sign
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index++] == '-')
			sign = -1;
	}
	//converting character to int
	while (str[index] && str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10;
		result += str[index++] - '0';
	}
result *= sign;
	return (result);	
}
