/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:15:48 by alakhida          #+#    #+#             */
/*   Updated: 2022/10/27 17:40:10 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** Applies the function 'f' to each character of the string 's',
** passing its index as the first argument and the address of the character as the second.
** Each character may be modified by the function 'f'.
*/
#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char*))
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
