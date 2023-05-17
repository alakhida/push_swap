/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:13:38 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/17 05:29:30 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void free_2d(char **str)
{
	int i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

size_t len_2d(char **str)
{
	size_t idx;

	idx = 0;
	while(str[idx])
		idx++;
	return (idx);
}